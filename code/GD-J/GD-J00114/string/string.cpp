#include<bits/stdc++.h>
using namespace std;
long long ans=0;
string ans1="",ans2="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		long long a;
		string c;
		cin>>a>>c;
		for (long long j=1;j<=a;j++)
		{
			s+=c;
		}
		//cout<<s<<" "<<s.size()<<'\n';
	}
//	//输入这里好像要超时
	string op,op1;
	for (long long i=0;i<s.size()/2;i++)
	{
		op=s[i];
		ans1+=op;
	}
	for (long long i=s.size()-1;i>s.size()/2;i--)
	{
		ans2+=s[i];
//		cout<<i<<" ";
	}
//	//cout<<'\n';
//	//	cout<<s<<" "<<ans1<<" "<<ans2<<'\n';
	for (long long i=0;i<s.size()/2;i++)
	{
		if (ans1[i]!=ans2[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
