#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],bset[35],maxn,ans,isspe=1,_isspe=1;
long long __pow(int x,int y)
{
	long long cnt=1;
	for(int i=1;i<=y;++i)
		cnt*=x;
	return cnt;
}
void devide(int x)
{
	long long cnt=-1;
	if(x==0)
	{
		isspe=0;
		maxn=max(maxn,(long long)1);
		return;
	}
	while(x!=0)
	{
		if(x%2==0)
			isspe=0;
		bset[++cnt]+=x%2;
		x/=2;
	}
	maxn=max(maxn,cnt+1);
}
void solve1()
{
	for(int i=maxn;i>=0;--i)
		if(bset[i]>=m)
		{
			//cout<<i<<" ";
			ans+=__pow(2,i);
		}
	//cout<<"\n";
	cout<<ans;
}
void solve2()
{
	for(int i=1;i<=n;++i)
	{
		long long temp;
		if(i==1)
			temp=a[2];
		else
			temp=a[1];
		for(int j=1;j<=n;++j)
		{
			if(i==j)
				continue;
			temp=temp&a[j];
		}
		ans=max(ans,temp);
	}
	cout<<ans<<"\n";
}
void solve3()
{
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			ans=max(ans,a[i]&a[j]);
	cout<<ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(i>1&&(a[i-1]+1)!=a[i])
			_isspe=0;
		devide(a[i]);
	}
	/*for(int i=0;i<=maxn;++i)
		cout<<bset[i]<<" ";
	cout<<"\n";*/
	if(m==1)
	{
		ans=a[1];
		for(int i=1;i<=n;++i)
			ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;++i)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		solve2();
		return 0;
	}
	if(m==2)
	{
		solve3();
		return 0;
	}
	if(isspe)
	{
		solve1();
		return 0;
	}
	if(_isspe){
		int cntn=0,rep=n;
		while(rep!=0)
		{
			rep/=2;
			++cntn;
		}
		if(n/2<m)
		{
			cout<<0;
			return 0;
		}
		if(n/2==m)
		{
			cout<<pow(2,cntn-2);
			return 0;
		}
		ans=a[n];
		--m;
		int cnt=0;
		while(m!=0)
		{
			m/=2;
			++cnt;
		}
		for(int i=0;i<=cnt-1;++i)
			ans-=__pow(2,i);
		cout<<ans;
		return 0;
	}
	cout<<1;
	return 0;
}
