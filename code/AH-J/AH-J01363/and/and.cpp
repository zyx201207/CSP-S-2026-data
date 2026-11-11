#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,Mod=998244353;
int a[N];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=29;i>=0;i--){
		int c=0,x=1LL<<i;
		for(int j=1;j<=n;j++)
			if(((a[j]&ans)==ans)&&((a[j]&x)==x))
				c++;
		if(c>=m)
			ans+=x; 
	}
	cout<<ans;
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--)
		solve();
	return 0;
}
