#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,m;
struct node{
	int n,s;
};
int a[maxn];
int ans[maxn];
node vis[maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(vis[a[i]].n==1){
			for(int j=1;j<=m;j++){
				if(vis[j].s<=vis[a[i]].s&&vis[j].s>=i&&j!=a[i]){
					vis[j].n=0,vis[j].s=0;
				}else{
					ans[j]+=vis[j].n;
				}
			}
		}else{
			vis[a[i]].n=1;
			vis[a[i]].s=i-1;
			for(int j=1;j<=m;j++){
				ans[j]+=vis[j].n;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
