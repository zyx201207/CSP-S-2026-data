#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],cnt[300005];
bool vis[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(0));
		for(int j=i;j<=n;j++){
			vis[j]=1;
			for(int k=i;k<j;k++){
				if(a[j]==a[k]&&vis[k]==1){
					for(int z=k;z<j;z++) vis[z]=0;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(vis[j]) cnt[a[j]]++; 
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" "; 
	return 0;
}

