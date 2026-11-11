#include<bits/stdc++.h>
using namespace std;
long long n,a,s,ans;
char c;
struct e{
	long long cnt;
	char cr;
};
vector<e>b;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	b.push_back({0,' '});
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		if(i>1&&b[b.size()-1].cr==c)
		{
			b[b.size()-1].cnt+=a;
		}
		else
		{
			b.push_back({a,c});
		}
		s+=a;
	}
	int len=b.size()-1,l=1,r=len;
	while(l<r)
	{
		if(!b[r].cnt)
		{
			r--;
		}
		if(!b[l].cnt)
		{
			l++;
		}
		if(b[l].cr!=b[r].cr)
		{
			ans+=min(b[l].cnt,b[r].cnt);
		}
		b[l].cnt=(b[l].cnt>b[r].cnt?b[l].cnt-b[r].cnt:0);
		b[r].cnt=(b[l].cnt>b[r].cnt?0:b[l].cnt-b[r].cnt);		
	}
	cout<<ans;
	return 0;
}
