#include<bits/stdc++.h>
using namespace std;
struct s1
{
	long a,b;
}s[200005];
bool cmp(s1 x,s1 y)
{
	return x.b>y.b;
}
long long cnt=1073741823,n,m,e[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a;
		for(int j=29;j>=0;j--)
		{
			if(s[i].a>=e[j])
			{
				s[i].b++;
			}
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		cnt&=s[i].a;
	}
	cout<<cnt;
	return 0;
}
