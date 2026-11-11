#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool vis[500005];
int d[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		int s=1;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				for(int k=1;;k++)
					if(d[s]!=a[j]){
						vis[d[s]]=0;
						d[s]=0;
						s--;
					}
					else break;
				s++;
			}
			else{
				d[s]=a[j];
				vis[d[s]]=1;
				s++;
			}	
		}
		for(int i=1;i<=m;i++)
			ans[i]+=vis[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
