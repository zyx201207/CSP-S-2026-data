#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define Rof(i,l,r) for(int i=(l);i<=(r);i++)
#define first fir
#define second sec
const int MAXN=1e5+5,INF=0x3f3f3f3f;
int n,m;
ll ans;
vector<int> a;
vector<char> c;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n,a.resize(n+1),c.resize(n+1);
	For(i,1,n) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		int mn=min(a[l],a[r]);
		a[l]-=mn,a[r]-=mn;
		if(c[l]!=c[r]) ans+=mn;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
