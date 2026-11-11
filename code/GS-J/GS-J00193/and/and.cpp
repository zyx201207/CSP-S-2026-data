#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],s=0,maxx=0;
string ej(int a)
{
	int s,lon[31],ll=0;
	string b;
	s=a;
	while(s)
	{
		ll++;
		lon[ll]=s%2;
		s/=2;
	}
	for(int i=ll;i>=1;i--)
	b=b+char('0'+lon[i]);
	return b;
}
long long yu(string a,string b)
{
	int c[100]={ };
	long long as=0;
	int l=max(a.length(),b.length());
	for(int i=0;i<l;i++)
	if(a[i]-'0'==1&&b[i]-'0'==1)
	c[i]=1;
	for(int i=l-1;i>=0;i--)
	as+=c[i]*pow(2,l)*10;
	return as;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
	for(int j=i;j<=n;j++)
	{
	s=0;
	for(int q=1;q<=m;q++)
	s+=yu(ej(a[i]),ej(a[j]));
	maxx=max(s,maxx);
	}
	cout<<maxx;
	return 0;
}
