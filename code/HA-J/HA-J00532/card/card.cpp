#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],f[M],vis[M],p;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		p=0;
		for(int j=1;j<=m;j++)f[j]=0;
		for(int j=i;j<=n;j++){
			if(!f[a[j]]){
				vis[a[j]]=j;
				f[a[j]]=1;
			}
			else{
				for(int k=vis[a[j]];k<=j;k++)f[a[k]]=0;
				f[a[j]]=1;
				vis[a[j]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			if(f[i])ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
