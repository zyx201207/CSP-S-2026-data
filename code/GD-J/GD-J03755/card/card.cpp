#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],c[300005];
bool vis[300005],vis2[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		memset(b,0,sizeof(b));
		int p=1;
		for(int j=i;j<=n;j++){
			if(!vis[b[j]]){
				if(vis2[a[j]]){
					for(int k=1;k<p;k++){
						if(b[k]==a[j]){
							for(int l=k;l<p;l++){
								b[l]=0,vis[b[l]]=1;
							}
							p=k;
							break;
						}
					}
				}
				if(j==n)b[p++]=a[n];
				else b[p++]=a[j],vis2[a[j]]=1;
			}
		}
		for(int j=1;j<p;j++){
			cout<<b[j]<<" ";
			c[b[j]]++;
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
