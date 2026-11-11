#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=200001;
int n;
long long total=1,ans=0;
long long num[N]; 
string s;
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
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	total-=1;
	long long l=(s.length()+1)/2-1;
	long long r=s.length()/2;
	for(;l>=0;l--,r++)
	{
		if(s[l]!=s[r])
			ans++;
	}
	cout<<ans;
} 
