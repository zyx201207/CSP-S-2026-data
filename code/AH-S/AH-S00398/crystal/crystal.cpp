#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define mmx 500001
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define refo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
vector<int> a(mmx,0);
signed main()
{
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,curm,cnt,mx=0;
	cin>>n>>m;
	fo (i,1,n) cin>>a[i];
	sort(a.begin()+1,a.begin()+n+1);
	fo (i,2,n)
	{
		curm=m;
		cnt=1;
		refo(j,i-1,1)
		{
			curm-=a[i]-a[j];
			++cnt;
			if (curm<0)
			{
				--cnt;
				break;
			}
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	return 0;
}
