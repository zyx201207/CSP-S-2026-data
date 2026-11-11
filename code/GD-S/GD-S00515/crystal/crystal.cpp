#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define uint unsigned long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define debug() cout<<"come here\n"
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		f=(ch=='-'?-1:f);
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
void writech(int x,char ch)
{
	write(x);
	putchar(ch);
}
int a[500005];
signed main()
{
//	system("fc crystal4.ans crystal.out");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int sum=0,ans=0;
	for(int l=1,r=2;r<=n;r++)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m&&l<r)
		{
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	writech(ans,'\n');
	return 0;
}

