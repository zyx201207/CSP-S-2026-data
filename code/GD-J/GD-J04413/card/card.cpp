#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],vis[300005],vis2[300005],ans[300005];
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)vis[j]=vis2[j]=0;
		for(int j=i;j<=n;j++){
			if(vis2[a[j]]&&vis[a[j]]>=1)
				for(int k=vis2[a[j]];k<j;k++){
					vis[a[k]]--,vis2[a[k]]=0;
				}
			vis[a[j]]++;
			vis2[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
