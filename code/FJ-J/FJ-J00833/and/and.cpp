#include<bits/stdc++.h>
using namespace std;
string abc(int x)
{
	string sum,cnt;
	while(x)
	{
		sum=sum+char(x%2+'0');
		x/=2;
	}
	for(int i=sum.size()-1;i>=0;i--)
	{
		cnt+=sum[i];
	}
	return cnt;
}
int ha(string s)
{
	int sum=0,cnt=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		sum=sum+(s[i]-'0')*pow(2,cnt);
		cnt++;
	}
	return sum;
}
string qu(string s)
{
	bool ok=0;
	string h;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='0')
		{
			ok=1;
		}
		if(ok==1)
		{
			h+=s[i];
		}
	}
	return h;
}
int a[1000006];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=m-1;
	int l=1;
	string z=abc(a[n]);
	string u;
	while(cnt)
	{
		string y=abc(a[n-l]);
		for(int i=1;i<=z.size()-y.size();i++)
		{
			y='0'+y;
		}
		for(int i=0;i<z.size();i++)
		{
			if(z[i]=='1'&&y[i]=='1')
			{
				s+='1';
			}
			else
			{
				s+='0';
			}
		}
		u=qu(s);
		z=qu(s);
		cnt--;
		l++;
		s="";
	}
	cout<<ha(u);
	return 0;
}
