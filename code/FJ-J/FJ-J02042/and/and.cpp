#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1000005;
long long a[N];
bool vis[N];
int er(long long x)
{
	string s;
	long long num=0;
	while(x!=0)
	{
		s+=to_string(x%2);
		x/=2;
	}
	long long k=1;
	for (int i=0;i<s.size();i++)
	{
		num+=(s[i]-'0')*k;
		k*=10;
	}
	return num;
}
int awy(long long x,long long y)
{
	if (x==y)
	{
	    long long p=0;
	    long long l=1;
	    while (x!=0)
	    {
	    	p+=x%10*l;
	    	l*=2;
	    	x/=10;
		}
		return p;
	}
	string s;
	while (x!=0 && y!=0)
	{
		if (x%10==y%10)
		{
			s+='1';
		}
		else
		{
			s+='0';
		}
		x/=10;
		y/=10;
	}
	long long num=0;
	long long k=1;
	for (int i=0;i<s.size();i++)
	{
		num+=(s[i]-'0')*k;
		k*=2; 
	}
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		vis[i]=false;
	}
	long long maxi,maxj;
	long long maxn;
	for (int k=1;k<m;k++)
	{
		maxn=-1;
		for (int i=1;i<=n;i++)
	    {
	    	if (vis[i]) continue;
		    for (int j=i+1;j<=n;j++)
		    {
		    	if (vis[j]) continue;
			    if (maxn<awy(er(a[i]),er(a[j])))
			    {
			    	maxn=awy(er(a[i]),er(a[j]));
			    	maxi=i;
			    	maxj=j;
			    }
		    }
	    }
	    n++;
	    a[n]=maxn;
	    vis[maxi]=true;
	    vis[maxj]=true;
	}
	cout << maxn;
	return 0;
}
