#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,a[10000005],maxn=0,countn[100005],ans,head[1000005],nextn[1000005],last;
bool vis[100005];
long long maxx(long a,long b)
{
	if (a>b)
		return a;
	return b;
}
int nextmuch(long long f,long long totalcost)
{
	long long add=0;
	for (long long i=f;i>1;i=a[nextn[i]])
	{
		if (nextn[i]==-1) continue;
		long long diff=a[f]-a[nextn[i]];
		if (diff > totalcost)
		{
			return add;
		}
		else if(totalcost>=diff*countn[a[nextn[i]]])
		{
			add+=countn[a[nextn[i]]];
			totalcost-=diff*countn[a[nextn[i]]];
		}
		else
		{
			
			return add;
		}
	}
}
int main()
{
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	last=-1;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		countn[a[i]]++;
	}
	sort(a,a+n+1);
	for (int i=1;i<=n;i++)
	{
		if (head[a[i]]==0)
		{
			head[a[i]]=i;
			nextn[a[i]]=last;
			last=i;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[a[i]])
			continue;
		vis[a[i]]=1;
		maxn=maxx(maxn,countn[a[i]]+nextmuch(i,m));
	}
	cout<<maxn;
	return 0;
 } 
