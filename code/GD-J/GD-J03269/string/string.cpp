#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,z,i,j,k,a[200005],b,c,d;
long long ii,jj,xx,yy;
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		m=m+a[i];
	}
	i=1,j=n;
	ii=1,jj=m;
	while(i<=j)
	{
		if(s[i]!=s[j])
		{
			b=b+min(a[i]-xx,yy);
			ii=ii+min(a[i]-xx,yy);
			jj=jj-min(a[i]-xx,yy);
		}
		else
		{
			ii=ii+min(a[i]-xx,yy);
			jj=jj-min(a[i]-xx,yy);
		}
		if(ii>a[i]+x)
		{
			x=x+a[i];
			i++;
		}
		else
		{
			xx=ii-(a[i]+x);
		}
		if(jj<=m-a[j]-y)
		{
			y=y+a[j];
			j--;
		}
		else
		{
			yy=jj-(m-a[j]-y);
		}
	}
	cout<<b;
	return 0;
}
/*
2 
2 a
3 a

3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
2 c

4
1 a
2 b
3 c
4 d
abbcccdddd

4
4 d
3 c
2 b
1 a
ddddcccbba
*/
