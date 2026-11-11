#include<bits/stdc++.h>
#define int long long 
#define rk(i,l,r) for(int i=l;i<=r;++i)
#define rp(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back 
#define lbt(x) x&(-x)
using namespace std;
const int N =5e5+10;
int a[N],n,m,x,y,s[N],dt,ans;

bool ck(int x,int b)
{
	if(s[x]-s[b-1]-(x-b+1)*(a[1]-a[b])<=m)return 1;
	else return 0;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rk(i,1,n)cin>>a[i];
	sort(a+1,a+n+1,[](int x,int y){return x>y;});
	//rk(i,1,n)cerr<<a[i]<<" \n"[i==n];
	rk(i,1,n)s[i]=s[i-1]+(a[1]-a[i]);
	//rk(i,1,n)cerr<<s[i]<<" \n"[i==n];
	rk(i,1,n)
	{
		dt+=a[1]-a[i];
		int l = i,r=n;
		while(l<=r)
		{
			int mid = (l+r)>>1;
			if(ck(mid,i))
			{
				ans=max(mid-i+1,ans);
				
				l=mid+1;
			}
			else r= mid-1;
		}

	}cout<<ans<<endl;
	

	return 0;
 } 
 
