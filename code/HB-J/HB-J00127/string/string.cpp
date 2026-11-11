#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
struct HWString
{
	ll num;
	char c;
}q[N];
ll ans,h,t;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
		cin>>q[i].num>>q[i].c;
	}
	h=1;
	while(h<t)
	{
		int cnt=min(q[h].num,q[t].num);
		if(q[h].c!=q[t].c)
		{
			ans+=cnt;
		}
		q[h].num-=cnt,q[t].num-=cnt;
		if(!q[h].num)
		{
			h++;
		}
		else
		{
			t--;
		}
	}
	cout<<ans;
    return 0;
}
