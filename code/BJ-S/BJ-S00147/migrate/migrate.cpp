#include<bits/stdc++.h>
using namespace std;
long long t;
char c;
int is[100001],cnt,ch[100005],ans;
bool fly(int l,int fr,int re){
	return (ch[fr]<=l&&ch[fr+1]+ch[fr+2]<=l&&ch[fr+2]<=l&&ch[fr+1]+ch[fr]);
}	
int check(int il,int l){
	for(int i=1;i<il;i++){
		ch[i]=abs(is[i]-is[i+1]);
	}
	for(int i=1;i<=il;i++){
		for(int j=1;j<=il;j++){
			if(i-j==3&&fly(l,i,j)) {
				ans++;
			}
		}
	}
	return ans+1;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int l,il;
		cin>>il>>l;
		for(int i=1;i<=il;i++){
			cin>>is[i];
		}
		cout<<check(il,l);
	}
	return 0;
}
