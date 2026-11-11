#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;
const int M=3e5+10;
int n;
int m;
int a[N];
int b[M];
int c[M];
int ans[M];

int r();

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	n=r();
	m=r();
	for(int i=1;i<=n;i++) a[i]=r();
	for( int i=1,h=0 ; i<=n ; i++,h=0 )
	{
		memset( b , 0 , sizeof(b) );
		for(int j=i,k;j<=n;j++)
		{
			k=a[j];
			if( b[k] > 0 && h > 0 && (b[k]<h || b[k]==h && k==c[h]) )
				h = b[k];
			else
			{
				c[ ++h ] = a[j];
				b[k] = h;
			}
		}
		for( int j=1 ; j<=h ; j++ )
			ans[ c[j] ]++;
	}
	
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	
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
