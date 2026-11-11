#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
const int N=2e5+10;
int n;
int a[N],c[N],d[N],ch[N],res=0;
ull b[N],s;
void check()
{
	s=0;
	for(int i=1;i<=res/2;i++)
	{
		if(!(b[i]==b[n-i+1]&&d[i]==d[n-i+1]))s+=(ch[i]==0?a[i]:b[i]);
	}
	return ;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char x[5];cin>>a[i]>>x;
		c[i]=x[0]-'a'+1;
		if(c[i]==c[i-1])
		{
			b[res]+=a[i];
			d[res]=c[i];
			ch[res]++;
		}
		else
		{
			res++;
			b[res]=a[i];
			d[res]=c[i];
		}
	}
	check();
	printf("%llu\n",s);
	return 0;
}
