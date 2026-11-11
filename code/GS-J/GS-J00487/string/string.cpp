#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a,sum,sum1,sum2;
	string c,s;
	for(int i;i<n;i++)
	{
		cin>>a>>c;
		for(int j;j<a;j++)
		{
			s+=c;
		}
		sum+=a;
	}
	for(int i;i<sum/2;i++)
	{
		sum2=sum;
		sum2--;
		if(s[i]!=s[sum2])
		{
			sum1+=1;
		}
	}
	cout<<sum1;
}
