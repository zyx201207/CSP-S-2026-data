#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0;
string s=" ",t=" ",c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>c;
		for(int j=1;j<=a;++j)
		{
			s+=c;
		}
	}
	long long l=s.size()-1;
	for(int i=1;i<=(l+1)/2;++i)
	{
		if(s[i]!=s[l-i+1]) ans++;
	}
	cout<<ans;
	return 0;
	//Trick||Treat!
}
