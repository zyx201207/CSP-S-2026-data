#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
string and1(string x,string y)
{
	int len1=x.size();
	int len2=y.size();
	string apt="",ans="";
	int mx=max(len1,len2);
	if(len1>len2)
	{
		for(int i=1; i<=len1-len2; i++)
			apt+='0';
		apt+=y;
		for(int i=0; i<=mx-1; i++)
		{
			if(x[i]=='0' || apt[i]=='0')
				ans+='0';
			else
				ans+='1';
		}
	}
	if(len1<len2)
	{
		for(int i=1; i<=len2-len1; i++)
			apt+='0';
		apt+=x;
		for(int i=0; i<=mx-1; i++)
		{
			if(apt[i]=='0' || y[i]=='0')
				ans+='0';
			else
				ans+='1';
		}
	}
	if(len1==len2)
		for(int i=0; i<=mx-1; i++)
		{
			if(x[i]=='0' || y[i]=='0')
				ans+='0';
			else
				ans+='1';
		}
	return ans;
}
int and2(string mj)
{
	int w=1;
	int eee=0;
	int len=mj.size();
	for(int i=0; i<=len-1; i++)
		eee+=w*(mj[i]-'0');
	w*=10;
	return eee;
}
int n,m,t,mx1;
int a[200010],b[200010],ans[200010];
string sum[200010];
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		b[i]=a[i];
		while(b[i]!=0)
		{
			char t=b[i]%2+'0';
			sum[i]+=t;
		}
	}
	for(int i=2; i<=n; i++)
	{
		ans[i]=and2(and1(sum[i-1]+sum[i]));
		mx1=max(ans[i],mx1);
	}
	cout<<mx1;
	return 0;
}
