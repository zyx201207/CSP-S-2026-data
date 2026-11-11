#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define Rof(i,l,r) for(int i=(l);i>=(r);i--)
#define first fir
#define second sec
const int MAXN=1e5+5,INF=0x3f3f3f3f;
int n,m;
vector<int> a,ans,ctd,ond;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m,a.resize(n+1);
	For(i,1,n) cin>>a[i];
	ans.resize(m+1),ctd.resize(m+1),ond.resize(m+1);
	For(s,1,n)
	{
		fill(ctd.begin(),ctd.end(),0);
		int top=0;
		For(i,s,n)
		{
			if(ctd[a[i]]==0) ctd[a[i]]++,ond[++top]=a[i];
			else while(ond[top]!=a[i]) ctd[ond[top]]--,top--;
		}
		For(i,1,top) ans[ond[i]]++;
	}
	For(i,1,m) cout<<ans[i]<<' ';
	return 0;
}
