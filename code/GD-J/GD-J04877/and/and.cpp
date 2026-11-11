#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],maxx,ans;
vector<ll> len[1005];
bool cmp(ll x,ll y){return x > y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ll t = a[i],s=0;
		while(t > 0)
		{
			t/=2;
			s++;
		}
		len[s].push_back(a[i]); 
		maxx= max(maxx,s);
	}
	if(len[maxx].size() >= m)
	{
		cout<<len[maxx][len[maxx].size()-m];
	}
	else
	{
		for(int i=maxx;i>=1;i--)
		{
			m-=len[i].size();
			if(m<=0)
			{
				m+=len[i].size();
				ans = len[i][0];
				for(int j=i+1;j<=maxx;j++)
				{
					if(len[j].size() != 0)
					{
						ans = ans & (len[j][len[j].size()-1]);
					}
				}
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
//5 3 
//31 3 1 15 7
