#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[500010];
int p[500010];
int cnt[500010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(l==0) {
				l++;
				b[l]=j;
				p[a[i]]=l;
			}
			else{
				for(int k=1;k<=l;k++){
					if(b[k]==a[j]) l=p[a[i]];
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int j=1;j<=l;j++){
				if(b[j]==a[k]) cnt[k]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
//Trick||Treat!