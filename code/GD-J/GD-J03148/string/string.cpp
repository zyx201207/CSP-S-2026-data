#include<bits/stdc++.h>
using namespace std;
long long n,a,sum,ans;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		ans+=a;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	for(int i=0;i<ans/2;i++)
	{
		int j=ans-i-1;
		if(s[i]==s[j])
		{
			continue;
		}
		else
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
