#include<iostream>
#include<algorithm>
using namespace std;
const int N=500001;
int n;
int ans=0;
long long m;
long long a[N];
int prefix[N]={0};
inline long long read()
{
	long long f=1,x=0;
	char c;
	c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
			f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		prefix[i]=prefix[i-1]+a[i];
	for(int i=1;i<=n;i++)//基准 
	{
		int cnt=0;
		long long m2=m;
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			int len=i-1-mid+1;
			if(len*a[i]-prefix[i-1]+prefix[mid-1]>m)//超限，需要右调 //从i-1到mid的前缀和 
			{
				l=mid+1;
			}
			else//没超限，可以再加 
				r=mid;
		}
		cnt=i-l+1;
		ans=max(ans,cnt);
				//cout<<"本轮"<<cnt<<endl;
	}
	cout<<ans;
}
