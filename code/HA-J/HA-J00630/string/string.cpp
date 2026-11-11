#include<bits/stdc++.h>
using namespace std;
struct f
{
	long long a;
	char c;
}b[210000];
long long n,ch=0,ans=0;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].a>>b[i].c;
		for(int j=1;j<=b[i].a;j++)
		{
			s+=b[i].c;
		}
		ch+=b[i].a;
	}
	for(int i=0;i<ch/2;i++)
	{
		if(s[i]!=s[ch-i-1])
		{
			ans+=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
