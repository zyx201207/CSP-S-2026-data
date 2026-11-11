#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int n;
long long sum;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int a;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long z=s.size()-1;
	for(long long i=0;i<=z/2;i++)
	{
		if(s[i]!=s[z-i])
			sum+=1;
	}
	cout<<sum;
	return 0;
}
