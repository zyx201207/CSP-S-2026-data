#include<bits/stdc++.h>
using namespace std;
const N=2e6+1;
int c,t,a[N],vis[N];
dfs(int x,n,m){
	return 0;
}
int main(){
	freopen("crystal2.in","r",stdin);
	freopen("crystal2.out","w",stdout);
	cin>>c>>t;
	for(int y=1;y<=t;y++)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++)
			{
				for(int i=1;i<=n;i++) vis[i]=0;
				dfs(1,i,j);
			}
		}
	}
	return 0;
}
