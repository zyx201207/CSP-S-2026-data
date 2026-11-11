#include <bits/stdc++.h>
using namespace std;
long long n,a;
string s,f;
bool huiwen(string ss)
{
	long long j=0;
	for (long long i = ss.size()-1;i >=0 ;i--)
	{
		if (ss[i]!=ss[j])
			return false;
		j++;
	}
	return true;
}
string fan(string ss)
{
	string x;
	for (long long i=ss.size()-1;i >= 0;i --)
		x+=ss[i];
	return x;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>a;
		string e;
		cin>>e;
		for (long long i = 1;i <= a;i ++)
			s+=e;
	}
	if (huiwen(s))
	{
		cout<<0;
		return 0;
	}
	long long ans=0;
	f=fan(s);
	for (long long i = 0;i < s.size();i ++)
	{
		if (s[i]!=f[i])
		{
			s[i]=f[i];
			ans++;
		}
		if (huiwen(s))
		{
			cout<<ans<<endl;
//			cout<<s<<endl;//
			return 0;
		}
	}
	return 0;
}

