#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=200001;
const int M=31;
int n,m,cmp_;
int a[N];
int high=0;//×î¸ßÎ» 
long long ans=0;
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
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
long long fast_pow(int a,int b)
{
	long long ans=1;
	while(b>0)
	{
		if(b&1)
			ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
int highbit(int n)
{
	int cnt=0;
	while(n!=0)
	{
		cnt++;
		n>>=1;
	}
	return max(0,cnt-1);
}
bool cmp(int a,int b)
{
	if((a&cmp_)&&(b&cmp_))
	{
		return a>b;
	}
	else
		if(a&cmp_)
			return true;
		else if(b&cmp_)
			return false;
		else
			return a>b;
		
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		high=max(high,highbit(a[i]));
	}
	sort(a+1,a+n+1);
	for(int i=high;i>=0;i--)
	{
		cmp_=fast_pow(2,i); 
		sort(a+1,a+n+1,cmp);
		long long now_ans=a[1];
		now_ans=a[1]; 
		for(int i=2;i<=m;i++)
		{
			now_ans=now_ans&a[i];
		}
		ans=max(ans,now_ans);
	}
	cout<<ans;
} 
