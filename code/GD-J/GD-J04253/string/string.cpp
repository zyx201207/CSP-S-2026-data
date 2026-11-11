#include <bits/stdc++.h>
#define int long long
#define rk(i,l,r) for(int i = l;i<=r;++i)
#define rp(i,r,l) for(int i = r;i>=l;--i) 
using namespace std;
const int N = 2e5+10;
pair<char,int> p[N],k1[N],k2[N];
int n,sum,pos,tot;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	rk(i,1,n)cin>>p[i].second>>p[i].first;
	rk(i,1,n)sum+=p[i].second;
	int t=sum>>1,lt;
//	cerr<<t<<endl;
	rk(i,1,n)
	{
		
		if(t-p[i].second>=0)
		{
			t-=p[i].second;
			k1[i]=p[i];
//			cerr<<1<<" ";
		}
		else if(t)
		{
			k1[i]={p[i].first,t};
			lt=i;
			k2[++tot]={p[i].first,p[i].second-t-(sum&1)};
			t=0;
			//cerr<<2<<" ";
		}
		else
		{
			k2[++tot]=p[i];
			//cerr<<3<<" ";
		}
		//cerr<<i<<" "<<t<<endl;
	}
	reverse(k1+1,k1+lt+1);
	int ans = 0,j=1;
	rk(i,1,tot)
	{
		while(k2[i].second&&j<=lt)
		{
			int len=min(k2[i].second,k1[j].second);
			if(k2[i].first!=k1[j].first)ans+=len;
			k2[i].second-=len;
			k1[j].second-=len;
			if(!k1[j].second)j++;
		}
	}cout<<ans;
	return 0;
}
