#include<bits/stdc++.h>
using namespace std;
long long n,c,sum;
string s,t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c>>t;
		for(int j=1;j<=c;j++)
		{
			s+=t;
		}
	}
	cout<<s.size()<<'\n';
	for(int i=0;i<ceil((s.size())/2.0);i++)
	{
		if(s[i]!=s[s.size()-i-1]) sum++;
	}
	cout<<sum;
}
//Trick||Treat!
