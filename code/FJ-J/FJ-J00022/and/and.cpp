#include<bits/stdc++.h>
using namespace std;
int n,m;
long long b;
string ans,sum;
struct num
{
	string s;
	long long id;
}a[200010];

string ter(int x)
{
	string s;
	while(x)
	{
		s=s+(char)(x%2+'0');
		x/=2;
	}
	return s;
}

long long ton(string x)
{
	long long cnt=0;
	for(int i=0;i<x.size();i++)
	{
		cnt=cnt*2+x[i]-'0';
	}
	return cnt;
}

bool cmp(num x,num y)
{
	if(x.s.size()!=y.s.size()) return x.s.size()>y.s.size();
	else
	{
		for(int i=0;i<x.s.size();i++)
			if(x.s[i]!=y.s[i]) return x.s[i]>y.s[i];
		return 1;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].id;
		a[i].s=ter(a[i].id);
	}
	sort(a+1,a+n+1,cmp);
	ans="";
	sum=a[1].s;
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<min(sum.size(),a[i].s.size());j++)
		{
			if(sum[sum.size()-j-1]=='1' && a[i].s[a[i].s.size()-j-1]=='1') ans=ans+'1';
			else ans=ans+'0';
		}
		sum=ans;
		ans="";
	}
	cout<<ton(sum);
	return 0;
}
