#include<bits/stdc++.h>
using namespace std;
int str[200010],ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		for(int j=sum;j<x+sum;j++)
			str[j]=y;
		sum+=x;
	}
	for(int i=1;i<=sum/2;i++)
		if(str[i]!=str[sum-i])
			ans++;
	cout<<ans;
	return 0;
}
