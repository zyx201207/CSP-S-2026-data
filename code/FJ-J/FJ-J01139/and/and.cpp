#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(long long a,long long b)
{
	return a>b;
}
long long b[35];
string er(long long a)
{
	int u=0;
	for(int i=1;i<=31;i++)
	{
		if(a>b[i]&&a<b[i+1])
		{
			u=i;
			break;
		}
	}
	string s;
	for(int i=u;i>=1;i--)
	{
		s+=char(a/b[i]+48);
		a=a%b[i];
	}
	return s;
}
int ad(string a,string c)
{
	int x=a.size()-1;
	int y=c.size()-1;
	string l;
	while(x>-1&&y>-1)
	{
		if(a[x]==c[x]) 
		{
			l+='1';
		}
		else l+='0';
		x--;
		y--;
	}
	int sum=0;
	for(int i=l.size()-1;i>=0;i--)
	{
		sum+=(int(l[i])-48)*(b[i+1]);
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	b[1]=1;
	for(int i=2;i<=31;i++)
	{
		b[i]=b[i-1]*2;
	}
	int lp=0;
	for(int i=1;i<=m-1;i++)
	{
		lp=max(lp,ad(er(a[i]),er(a[i+1])));
	}
	cout<<lp<<endl;
	return 0; 
}
