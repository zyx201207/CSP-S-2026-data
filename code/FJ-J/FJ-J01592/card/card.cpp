#include<bits/stdc++.h>
using namespace std;
const int N=200005;
#define int long long
int a[N],b[N],vis[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				b[j]=a[j];
				vis[a[j]]=1;
			}else{			
			
				for(int k=i;k<=j;k++){
					if(a[k]==a[j]){
						for(int o=k;o<=j;o++){
							b[o]=0;
							vis[o]=0;
						}
						break;
					}
				}
				b[j]=a[j];vis[a[j]]=1;
			}
		}
		
		for(int j=i;j<=n;j++){
			ans[b[j]]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	   return 0;
}


