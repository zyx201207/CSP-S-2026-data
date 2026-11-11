#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define Rof(i,l,r) for(int i=(l);i>=(r);i--)
const int MAXN=1e5+5,INF=0x3f3f3f3f;
int n,m,ans,now;
vector<int> a;
void dfs(int l,int r,int m,int cnt)
{
	int tl=INF,tr=INF;
	if(l>1) tl=now-a[l-1];
	if(r<n) tr=(a[r+1]-now)*(r-l+1);
	if(tl>m&&tr>m)
	{
		ans=max(ans,cnt);
		return;
	}
	int al=a[l-1],ar=now;
	if(tl<=tr&&tl<=m) a[l-1]=now,dfs(l-1,r,m-tl,cnt+1);
	a[l-1]=al;
	if(tr<=tl&&tr<=m) now=a[r+1],dfs(l,r+1,m-tr,cnt+1);
	now=ar;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m,a.resize(n+1);
	For(i,1,n) cin>>a[i];
	sort(a.begin()+1,a.end());
	now=a[n/2+1];
	dfs(n/2+1,n/2+1,m,1);
	cout<<ans;
	return 0;
}
