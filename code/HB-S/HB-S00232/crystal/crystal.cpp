#include<bits/stdc++.h>
using namespace std;
namespace std{
	using i64=long long;
	using u32=unsigned int;
	using u64=unsigned long long;
	using p32=pair<int,int>;
	using p64=pair<long long,long long>;
	#define all(x) (x).begin(),(x).end()
	#define one(x) (x).first
	#define two(x) (x).second
}
#define int long long
int n,V;
int a[500005],sum[500005];
bool check(int l,int r){return (a[r]*(r-l+1)-(sum[r]-sum[l-1]))<=V;}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>V;
	for(int i=1;i<=n;i++)	cin>>a[i];
	int p=1,ans=1;sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
		{while(p<=i&&!check(p,i)&&(++p));ans=max(ans,i-p+1);}
	cout<<ans<<"\n";
	return 0;
}