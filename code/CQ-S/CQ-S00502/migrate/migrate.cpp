#include<bits/stdc++.h>
#define int long long
using namespace std;

mt19937_64 rnd(time(0));
int nxt[5010][15],lst[5010][15],nxt_val[5010][15],lst_val[5010][15],a[5010],val[5010],n,d;
map <int,int> mp;

int go1(int l,int r)
{
	int res=0;
	for(int i=12;i>=0;i--) if(nxt[l][i]<r) res^=nxt_val[l][i],l=nxt[l][i];
	if(a[r]-a[l]<=d) return res;
	return 0;
}

int go2(int l,int r)
{
	int res=0;
	for(int i=12;i>=0;i--) if(lst[r][i]>l) res^=lst_val[r][i],r=lst[r][i];
	if(a[r]-a[l]<=d) return res;
	return 0;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i],val[i]=rnd();
		for(int i=1;i<=n;i++) 
		{
			nxt[i][0]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			lst[i][0]=lower_bound(a+1,a+n+1,a[i]-d)-a;
			nxt_val[i][0]=val[nxt[i][0]];
			lst_val[i][0]=val[lst[i][0]];
		}
		for(int j=1;j<=12;j++) for(int i=1;i<=n;i++) 
		{
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
			lst[i][j]=lst[lst[i][j-1]][j-1];
			nxt_val[i][j]=nxt_val[i][j-1]^nxt_val[nxt[i][j-1]][j-1];
			lst_val[i][j]=lst_val[i][j-1]^lst_val[lst[i][j-1]][j-1];
		}
		mp.clear();
		for(int i=1;i<n;i++) mp[val[i]^val[i+1]]=1;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(mp[go1(i,j)^go2(i,j)]) ans++;
		cout<<ans<<endl;
	}
}
