#include<iostream>
#define int long long
using namespace std;
int n,m;
int a[200005];
bool vis[200005];
int ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=30;i>=0;--i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			if(vis[j]==0){
				int b=(a[j]>>i)%2;
				if(b==1)++cnt;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;++j){
				if(vis[j]==0){
					int b=(a[j]>>i)%2;
					if(b==0)vis[j]=1;
				}
			}
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
} 
