#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
#define inr(L,R,l,r) (l<=L and R<=r)
#define ofr(L,R,l,r) (L>r or l>R)
#define re return
#define ll long long
#define ull unsigned long long
#define ioo cin.tie(0)->sync_with_stdio(0);cout.tie(0)->sync_with_stdio(0);
using namespace std;
const int maxn=5e5+1145;

ll n,m;
ll a[maxn],s[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ioo;
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	int j=1;
	int ans=0;
	rep(i,1,n)
	{
		while(j<i and a[i]*(1ll*i-j+1)-(s[i]-s[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
}
