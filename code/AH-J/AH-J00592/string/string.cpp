#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	string ss=s;
	int sum=0;
	reverse(ss.begin(),ss.end());
	int k=s.size();
	for(int i=0;i<k;i++)
	{
		if(s[i]!=ss[i])
		{
			sum++;
		}
	}
	cout<<sum/2;
	return 0;
}
