#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
const int N=2e5+5;
int n,m,a[N],cnt[35],vis[N][35],f[N],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if((a[i]>>j)&1) cnt[j]++,vis[i][j]=1;
		}
	}
	for(int j=30;j>=0;j--){
		if(cnt[j]>=m){
			for(int i=1;i<=n;i++){
				if(!vis[i][j]&&!f[i]){
					f[i]=1;
					for(int k=0;k<=30;k++){
						if((a[i]>>k)&1){
							vis[i][k]=0;
							cnt[k]--;
						}
					}
				}
			}
			ans+=(1ll<<j);
		}
	}
	cout<<ans;
	return 0;
}
