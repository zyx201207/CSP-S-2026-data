#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int sum[500005];
int vis[500005];
int ans[500005];
int a[500005];
int out[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int k=1;
	for(int i=1;i<=n;i++){
		k=1;
		memset(vis,0,sizeof vis);
		memset(out,0,sizeof out);
		for(int j=i;j<=n;j++){
			int o=arr[j];//第j张卡牌点数 
			if(vis[o]==0){
				vis[o]=k;
				a[k++]=o;
			}
			else if(out[o]==-1){
				continue;
			}
			else{
				int lll=k;
				for(int c=vis[o];c<lll;c++){
					out[a[c]]=-1;
					k--;
				}
				a[k++]=o ;
			}
		}
		for(int j=1;j<k;j++){
			ans[a[j]]++;
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
