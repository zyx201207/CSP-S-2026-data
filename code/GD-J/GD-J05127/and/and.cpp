#include<bits/stdc++.h>
using namespace std;
long long n,m,dp[200005];
string a[200005];
string zh(string s)
{
	string a="";
	while(s!="0")
	{
		string s1="";
		long long ys=0;
		for(int i=0;i<s.size();i++)
		{
			long long js=s[i]-'0'+ys*10;
			ys=js%2;
			s1=s1+char(js/2+'0');
		}
		while(s1[0]=='0'&&s1.size()>1)
			s1.erase(0,1);
		s=s1;
		if(ys==1)
			a="1"+a;
		else
			a="0"+a;
	}
	return a;
}
bool cmp(string a,string b)
{
	if(a.size()==b.size())
	{
		for(int i=0;i<a.size();i++)
		{
			if(a[i]<b[i])
				return false;
			if(a[i]>b[i])
				return true;
		}
		return false;
	}
	return a.size()>b.size();
}
string an(string a,string b)
{
	string c="";
	if(a.size()>b.size())
		a.erase(0,a.size()-b.size());
	if(a.size()<b.size())
		b.erase(0,b.size()-a.size());
	for(int i=0;i<a.size();i++)
		if(a[i]=='1'&&b[i]=='1')
			c=c+"1";
		else
			c=c+"0";
	return c;
}
string jc(long long x)
{
	string s="1";
	while(x--)
	{
		long long jw=0;
		for(int i=s.size()-1;i>=0;i--)
		{
			long long js=s[i]-'0'+jw;
			js*=2;
			jw=js/10;
			js%=10;
			s[i]=js+'0';
		}
		if(jw>0)
			s=char(jw+'0')+s;
	}
	return s;
}
string jf(string s1,string s2)
{
	while(s1.size()>s2.size())
		s2="0"+s2;
	while(s2.size()>s1.size())
		s1="0"+s1;
	string ans="";
	long long jw=0;
	for(int i=s1.size()-1;i>=0;i--)
	{
		long long js=s1[i]+s2[i]-2*'0'+jw;
		jw=js/10;
		js%=10;
		ans=char(js+'0')+ans;
	}
	if(jw!=0)
		ans="1"+ans;
	return ans;
}
void anf(string s)
{
	string ans="0";
	for(int i=s.size()-1;i>=0;i--)
		if(s[i]=='1')
		{
			string s1=jc(s.size()-i-1);
			ans=jf(ans,s1);
		}
	printf("%s",a[m]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
		a[i]=zh(a[i]);
	for(int i=2;i<=m;i++)
		a[i]=an(a[i],a[i-1]);
	anf(a[m]);
	return 0;
}
