#include <iostream>//AC!
#include <vector>
using namespace std;
long long n,m,tong[40],now=-1,ans=0;
long long old,nw;
bool flag[200005][40];
vector<long long> cun[2];
long long qpow(long long a,long long b)
{
	long long res=1;
	while(b>0)
	{
		if(b&1) res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long a,cnt=0;
		cin>>a;
		while(a>0)
		{
			if(a&1)
			{
				flag[i][cnt]=1;
				tong[cnt]++;
			}
			a>>=1;
			cnt++;
		}
	}
	for(int i=32;i>=0;i--)
		if(tong[i]>=m)
		{
			now=i;
			break;
		}
	if(now==-1)
	{
		cout<<0;
		return 0;
	}
	old=0;
	nw=1;
	for(int i=1;i<=n;i++)
		if(flag[i][now]==1) cun[nw].push_back(i);
	swap(old,nw);	
	while(now>=0)
	{
		ans=ans+qpow(2,now);
		for(now=now-1;now>=0;now--)
		{
			if(tong[now]<m) continue;
			int len=cun[old].size();
			for(int i=0;i<len;i++)
			{
				int xx=cun[old][i];
				if(flag[xx][now]==1) cun[nw].push_back(xx);
			}
			if((long long)cun[nw].size()>=m) break;
			cun[nw].clear();
		}
		if(now<0) break;
		cun[old].clear();
		swap(old,nw);
	}
	cout<<ans;
	return 0;
}
