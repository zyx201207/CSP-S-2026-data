#include<bits/stdc++.h>

using namespace std;

#define MAXN 200010
typedef pair<long long,long long> PLL;

struct str
{
	long long num;
	char c;
	long long l,r;
}a[MAXN];
long long siz=0,ans=0;
int n;
PLL b[MAXN];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("string5.in","r",stdin);
//	freopen("string5.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
		siz+=a[i].num;
		if(i==1)
		{
			a[i].l=0,a[i].r=a[i].num-1;
		}
		else
		{
			a[i].l=a[i-1].r+1,a[i].r=a[i-1].r+a[i].num;
		}
		b[i]=make_pair(a[i].l,a[i].r);
	}
	long long i=0,idxi=1,idx=n;
	while(i<=siz/2)
	{
		long long tmp=siz-i-1;
		while(b[idxi].second<i)
		{
			idxi++;
		}
		while(b[idx].first>tmp)
		{
			idx--;
		}
		if(a[idxi].c!=a[idx].c)
		{
			ans++;
		}
		i++;
	}
	cout<<ans<<endl;
	
	return 0;
}
