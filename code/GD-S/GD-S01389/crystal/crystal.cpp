#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
#define Tie cin.tie(0)->sync_with_stdio(0)
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using namespace std;
const int N=5e5+5;
int T,n,m,ans,l;
int a[N];
__int128 s;
signed main()
{
	// fre(crystal);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	Tie,cin>>n>>m,l=1;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n)
	{
		if(i<n&&a[i]==a[i+1]) 
		{
			s+=a[i];
			continue;
		}
		__int128 need=(__int128)(i-l)*a[i]-s;
		if(need<=m) ans=max(ans,i);
		else
		{
			do
			{
				need-=a[i]-a[l],s-=a[l],l++;
			} while (need>m&&l<i);
			ans=max(ans,i-l+1);
		}
		s+=a[i];
	}
	cout<<ans;
	return 0;
}//100pts