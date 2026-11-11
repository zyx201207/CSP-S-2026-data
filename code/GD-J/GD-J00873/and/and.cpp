#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+5,M=1e2+5;
const int INF=0x3f3f3f3f,MOD=1e9+7;
typedef long long LL;
int n,m,a[N],ans;
bool vis[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&(a[j]&(1<<i)))
				cnt++;
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(vis[j]||(a[j]&(1<<i)))continue;
				vis[j] = 1;
			}
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}

