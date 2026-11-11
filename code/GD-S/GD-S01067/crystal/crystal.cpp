#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int,int>
#define lg(x) (63-__builtin_clzll(x))
typedef long long ll;
using namespace std;
const int N=5e5+100;
ll n,m;
ll a[N],pre[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]+=pre[i-1]+a[i];
	for(ll r=1,l=1;r<=n;r++){
		while(l<=r&&(r-l+1)*a[r]-(pre[r]-pre[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

1 1
10
*/
