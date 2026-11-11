#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt[31],use[200000],fm=31,ans=2147483647;
struct number
{
	int l,x[31];
};
number q[200000];
bool cmp(number a,number b)
{
	return a.l>b.l;
}
void push(int i)
{
	int t=q[i].l,z=30;
	string s="";
	while(t)
	{
		q[i].x[z]=(t&1);
		if(t&1)
		{
			cnt[z]++;
		}
		t>>=1;
		z--;
	}
	return;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&q[i].l);
		push(i);
	}
	for(int i=0;i<=30;i++)
	{
		if(cnt[i]>=m)
		{
			fm=i;
			break;
		}
	}
	if(fm==31)
	{
		cout<<"0";
	}
	else
	{
		long long lim=1<<(31-fm);
		for(int i=0;i<n;i++)
		{	
			q[i].l%=lim;
		}
		sort(q,q+n,cmp);
		for(int i=0;i<m;i++)
		{
			ans=ans&q[i].l;
		}
		cout<<ans;
	}
	return 0;
}
