#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;
int n;
int m;
int a[N];
int ans;

int r();

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	n=r();
	m=r();
	for(int i=1;i<=n;i++)
	{
		a[i]=r();
	}
	
	sort(a+1,a+n+1,[](int x,int y){ return x>y; });
	
	ans=a[1];
	for(int i=2;i<=m;i++)
		ans&=a[i];
	
	cout<<ans<<endl;
	
	return 0;
}

int r()
{
	char c=getchar();
	int flag=1;
	while( c<'0' || c>'9' )
	{
		if( c=='-' ) flag=-1;
		else flag=1;
		c=getchar();
	}
	int x=0;
	while( c>='0' && c<='9' )
	{
		x = (x<<3) + (x<<1) + c - '0';
		c=getchar();
	}
	return x*flag;
}
