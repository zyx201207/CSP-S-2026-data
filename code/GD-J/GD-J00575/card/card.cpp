#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int vis[N];
int cnt[N];
int pos[N];
signed main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=cnt[j]=0;
		}
		for(int j=i;j<=n;j++){
			vis[a[j]]++;
			if(vis[a[j]]==1){
				pos[a[j]]=j;
			}
			if(vis[a[j]]==2){
				vis[a[j]]=1;
				for(int k=pos[a[j]];k<=j;k++){
					cnt[k]=1;
				}
				pos[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(!cnt[j]){
				vis[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
} 
