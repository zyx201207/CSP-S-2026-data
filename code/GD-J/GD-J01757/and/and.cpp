#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int M=1e6+10;
const int K=15;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
int n,m,a[N];
int cnt[40];
bool vis[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=30;j>=0;--j){
			if(a[i]&(1<<j))cnt[j]++;
		}
	}
	int ans=0;
	for(int j=30;j>=0;--j){
		if(cnt[j]<m)continue;
		ans+=(1<<j);
//		cout<<j<<endl;
		for(int i=0;i<=30;++i){
			cnt[i]=0; 
		}
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			if(a[i]&(1<<j)){
//				cout<<a[i]<<endl;
				for(int k=j;k>=0;--k){
					if(a[i]&(1<<k))cnt[k]++;
				}
			}else{
				vis[i]=1;
			}
		}
//		for(int i=1;i<=n;++i){
//			cout<<vis[i]<<" ";
//		}
//		cout<<endl;
//		for(int i=0;i<=30;++i){
//			cout<<cnt[i]<<" ";
//		}
//		cout<<endl;
	}
	cout<<ans;
	return 0;
}

