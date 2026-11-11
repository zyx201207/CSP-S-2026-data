#include<bits/stdc++.h>
using namespace std;
int a[100000005];
char b[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	string s=" ";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	int sum1=sum/2;
	int ans=0;
	for(int i=sum1;i>=1;i--)
	{
		if(s[i]!=s[sum-i+1])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
