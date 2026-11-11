#include<bits/stdc++.h>
using namespace std;

struct t
{
	int num;
	char c;
};

int n;
unsigned long long sum;
t a[200010];

void in(int &x)
{
	x=0;int f=1,c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
}

void out(unsigned long long x)
{
	if(x<0) x=-x,putchar('-');
	if(x>=10) out(x/10);
	putchar(x%10+'0');
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	in(n);
	for(int i=1;i<=n;i++) 
	{
		in(a[i].num);
		cin>>a[i].c;
	}
	for(int i=1,j=n;i<=j;)
	{
		if(i==j) break;
		int minn=min(a[i].num,a[j].num);
		a[i].num-=minn,a[j].num-=minn;
		if(a[i].c!=a[j].c) sum+=minn;
		if(!a[i].num) i++;
		if(!a[j].num) j--;
	}
	out(sum);
	return 0;
}
