#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long

struct s
{
	int ord;
	int las;
}c[200005];

int n,m,cnt;
int a[200005],b[200005][35],d[200005];

bool isa1(int l)
{
	cnt=0;
	for(int j=1; j<=n; j++)
	{
		if(b[j][l])
		{
			cnt++;
			c[cnt].ord=a[j];
			c[cnt].las=c[cnt].ord;
		}
	}
	return (cnt>=m);
}

int lc1(int a)
{
	int len=0,aa=a;
	while(aa)
	{
		if(aa&1) len++;
		else break;
		aa/=2;
	}
	return len;
}

bool cmp(s a,s b) {
	if(lc1(a.las)!=lc1(b.las)) return lc1(a.las)>lc1(b.las);
	return a.ord>b.ord;
}

signed main()
{
	/freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int factor=0;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		int aa=a[i],len=1;
		while(aa)
		{
			b[i][len]=(aa&1);
			len++;
			aa/=2;
		}
	}
	for(int i=31; i>=1; i--)
	{
		if(isa1(i))
		{
			factor=i;
			break;
		}
	}
	for(int i=1; i<=cnt; i++)
		c[i].las%=factor; 
	sort(c+1,c+cnt+1,cmp);
	cout<<endl<<cnt<<" ";
	cout<<factor<<endl;
	int ans=c[1].ord;
	for(int i=2; i<=m; i++)
		ans&=c[i].ord;
	cout<<ans<<endl;
	return 0;
}

/*
5 3
31 3 1 15 7
*/
