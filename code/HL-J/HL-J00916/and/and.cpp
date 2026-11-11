#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int a[200005];
bool cmp(int s,int d)
{
	return s>d;
}
string er(int f)
{
	string s="";
	while(f>0)
	{
		s+=(f%2+'0');
		f/=2;
	}
	return s;
}
int shi(string h)
{
	int j=0;
	for(int i=0;i<(int)(h.length());i++)
	{
		int g=int(h[i]-'0');
		g=g*pow(2,i);
		j+=g;
	}
	return j;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	k=a[1];
	for(int i=2;i<=m;i++)
	{
		string o,p,y;
		o=er(k);
		p=er(a[i]);
		for(int j=0;j<max(o.length(),p.length());j++)
		{
			if(j<=min(o.length(),p.length()))
			{
				if(o[j]=='1' && p[j]=='1')
				{
					y+='1';
				}
				else
				{
					y+='0';
				}
			}
			else
			{
				y+='0';
			}
		}
		k=shi(y);
	}
	cout<<k;
	return 0;
	
}