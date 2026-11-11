#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,sum=0;
	char a[20005],c[20005],s[20005],long1=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
 	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		s[long1++]=c[i];
	}
	int long2=long1-1; 
	for(int i=0;i<long1/2;i++)
	{
		if(s[long2--]!=s[i]) sum++;
	}
	cout<<sum;
	return 0;
}
