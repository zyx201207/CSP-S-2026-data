#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,maxx=1;
int a[N],b[N];
int s[210];
void dfs(int x,int mm){
	if(x>n){
		for(int i=0;i<210;i++){
			s[i]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			s[b[i]+100]++;
		}
		for(int i=0;i<210;i++){
			ans=max(s[i],ans);
		}
		maxx=max(ans,maxx);
	}else{
	    for(int i=0;i<=mm;i++){
		    b[x]=a[x]+i;
		    dfs(x+1,mm-i);
    	}
    }
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=0;
	}
	dfs(1,m);
	cout <<maxx;
	return 0;
}
