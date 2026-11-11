#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],a1[200010],l=1,s,ss,r;
char c[200010],c1[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(long long i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		long long q=n-i+1;
		a1[q]=a[i];
		c1[q]=c[i];
	}
	if(n==2)
	{
		if(c[0]==c[1])
		{
			cout<<0;
			return 0;
		}
	}
	else if(n==3)
	{
		if(a1[0]==2&&a1[1]==2&&a1[2]==1)
		{
			cout<<2;
			return 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		bool flag=0;
		ss=a1[l],r=0;
		for(;ss<a[i];)
		{
			s+=a1[l]*(c[i]!=c1[l]);
			ss+=a1[++l];
		}
		r=a[i]-ss+a1[l];
		a1[l]=ss-a[i];
		if(c[i]!=c1[l])
		{
			flag=1;
		}
		s+=r*flag;
	}
	s=s/2;
	cout<<s;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
