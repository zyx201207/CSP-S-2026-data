//GZ-J00120 ³ÂÜÆåû
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
void ss()
{
	int n;
	cin>>n;
	ll ans=0;
	vector<pair<ll,char> >a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
	ll l=1,r=n;
	while(l<=r)
	{
		if(l==r) break;
		if(a[l].se==a[r].se)
		{
			if(a[l].fi<a[r].fi)
			{
				l++;
				if(a[l].se==a[r].se)
				{
					a[l].fi-=a[r].fi-a[l-1].fi;
					r--;
				}
				else
				{
					ans+=a[r].fi-a[l-1].fi;
					a[l].fi-=a[r].fi-a[l-1].fi;
					r--;
				}
			}
			else if(a[l].fi>a[r].fi)
			{
				r--;
				if(a[l].se==a[r].se)
				{
					a[r].fi-=a[l].fi-a[r+1].fi;
					l++;
				}
				else
				{
					ans+=a[l].fi-a[r+1].fi;
					a[r].fi-=a[l].fi-a[r+1].fi;
					l++;
				}
			}
			else l++,r--;
		}
		else
		{
			ans+=min(a[l].fi,a[r].fi);
			if(a[l].fi<a[r].fi)
			{
				l++;
				if(a[l].se==a[r].se)
				{
					a[l].fi-=a[r].fi-a[l-1].fi;
					r--;
				}
				else
				{
					ans+=a[r].fi-a[l-1].fi;
					a[l].fi-=a[r].fi-a[l-1].fi;
					r--;
				}
			}
			else if(a[l].fi>a[r].fi)
			{
				r--;
				if(a[l].se==a[r].se)
				{
					a[r].fi-=a[l].fi-a[r+1].fi;
					l++;
				}
				else
				{
					ans+=a[l].fi-a[r+1].fi;
					a[r].fi-=a[l].fi-a[r+1].fi;
					l++;
				}
			}
			else l++,r--;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--) ss();
	return 0;
}
