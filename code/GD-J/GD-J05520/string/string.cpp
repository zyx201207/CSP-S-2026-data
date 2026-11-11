#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	int j=1;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int k=j;k<=j+x;k++)
		{
			a[k]=y;
		}
		j+=x;
	}
	int cnt=0;
	for(int i=1;i<=j/2;i++)
	{
		if(i==j-i+1)break;
		if(a[i]!=a[j-i+1]) cnt++;
		if(i==j-i)break;
	}
	cout<<cnt;
	return 0;
}
