#include<bits/stdc++.h>
using namespace std;
int a[300005],ans[300005],b[300005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		int t=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				t++;
				b[t]=a[j];
				vis[a[j]]=1;
			}
			else{
				for(int k=1;k<=t;k++){
					if(a[k]==a[j]){
						int s=0;
						for(int w=k;w<=t;w++){
							vis[a[w]]=0;
							a[w]=0;
							s++;
						}
						t=t-s+1;
						b[t]=a[j];
						t++;
						vis[a[j]]=1;
						break;
					}
				}
			}
		}
		for(int j=1;j<=t;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
