#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX=5e2+5;
typedef long long ll;
ll ans=0;
struct station
{
	ll w;
	ll line;
	ll t;
	ll rank;
	ll id;
	ll cnt;
};
station s[MAX];
ll c,n,m,d,q;
ll k[MAX],x,y;
bool cmp(station x,station y)
{
	return x.id<y.id;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	  scanf("%lld",&s[i].w);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%lld%lld",&s[i].id,&s[i].t);
			s[i].line=i;
			s[i].rank=j;
			s[i].cnt++;
		}
	}
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&x,&y);
		ans=0;
		station st,ed,trans;
		for(int j=1;j<=m;j++)
		  if(s[j].id==x)
		  {
		  	  st=s[j];
		  	  break;
		  }
		  else if(s[j].id==y)
		  {
		  	  ed=s[j];
		  	  break;
		  }
		ans+=(st.w+st.t);
		for(int j=1;j<=m;j++)
		  if(s[j].cnt>=2)
		  {
			  trans=s[j];
			  break;
		  }
		for(ll j=st.id+1;s[j].id!=ed.id&&j<=trans.id;j++)
		  if(s[j].line==st.line)
			ans+=s[j].t;
		for(int j=trans.id+1;s[j].id!=st.id&&j<ed.id;j++)
		  if(s[j].line==ed.line)
		    ans+=s[j].t;
		ans+=(ed.t+ed.w);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}