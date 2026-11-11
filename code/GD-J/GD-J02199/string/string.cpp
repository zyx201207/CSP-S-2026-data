#include<bits/stdc++.h>
using namespace std;
int a[1000000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int b;
		cin>>b;
		char c;
		for(int j=0;j<b;i++)
		{
			a[j]=c;
		}
		
	}
	for(int i=n;i>=0;i--)
	{
		if(a[i]!=a[j])
		cnt++;
	}
	cout<<cnt;
	return 0;
}
