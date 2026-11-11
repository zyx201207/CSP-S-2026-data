#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int chaf[N];
int ans=0;
int flag;
int maxn=-1;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		flag=0;
		ans=0;
		for(int j=1;j<=n;j++){
			flag+=abs(a[j]-a[i]);
			if(flag<=m){
				ans++;
			} else {
				continue;
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
} 
