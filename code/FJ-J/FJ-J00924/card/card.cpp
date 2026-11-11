#include<bits/stdc++.h>
using namespace std;
#define int long long
int T=1,n,m;
int a[500010];
int ans[300010];
map<int,int> v;
int vis[300010];

void solve(){
	cin>>n>>m;
	bool f=1; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=0;
	}
	if(f){
		for(int i=1;i<=n;i++){
			ans[a[i]]+= i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=cnt;j++)
				v[j]=0;
			for(int j=1;j<=m;j++)
				vis[j]=0;
			cnt=0;
			for(int j=i;j<=n;j++){
				int t=a[j];
				if(vis[t]){
					for(int k=cnt;k>=1;k--){
						cnt=k;
						if(v[k]==t)break;
						vis[v[k]]=0;
						v[k]=0;
					}
				}else{
					v[++cnt]=t;
					vis[t]=1;
				}
			}
			for(int j=1;j<=cnt;j++){
				ans[v[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
} 

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
