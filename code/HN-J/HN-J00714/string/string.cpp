#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long aj;
		string nj;
		cin>>aj>>nj;
		for(int j=1;j<=aj;j++)
		{
			s+=nj;
		}
	}
	string s1=s;
	reverse(s.begin(),s.end());
	if(s==s1)
	{
		cout<<0;
	}
	else
	{
		long long sum=0;
		for(int i=0;i<(s1.size()/2);i++)
		{
			long long a=s1.size()-1-i;
			if(s1[i]!=s1[a])
			{
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
