#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
string ans;
string s[200005];
bool sort1(string a,string b)
{
	return a>=b;
}
string f(string a,string b)
{
	string cnt;
	int p=a.size(),q=b.size();
	if(p>=q)
	{
		for(int i=0;i<p;i++)
		{
			if(i>q)
			{
				cnt+=a[i];
			}
			else
			{
				cnt+=char(a[i]&b[i]);
			}
		}
	}
	else
	{
		for(int i=0;i<q;i++)
		{
			if(i>p)
			{
				cnt+=b[i];
			}
			else
			{
				cnt+=char(a[i]&b[i]);
			}
		}
	}
	return cnt;
}
int main()
{
	cin.tie(0);cout.tie(0);
	//freopen("and.in","w",stdin);
	//freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1,sort1);
	ans=s[1];
	for(int i=2;i<=m;i++)
	{
		ans=f(ans,s[i]);
		//cout<<f(ans,s[i]);
	}
	cout<<ans;
	return 0;
}

