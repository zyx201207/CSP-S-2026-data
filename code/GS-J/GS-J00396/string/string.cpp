#include<bits/stdc++.h>
using namespace std;
	long long n,a,num=0,ans,d=0,b[200010];
	char c; 
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		num=num+a;
		for(int j=d;j<=num;j++)
		{
		b[j]=c;
		d+=a;
		}
	}
	for(int z=0;z<num/2;z++)
	{
		if(b[z]!=b[num-z])
			ans++;
	}
	cout<<ans;
	return 0;
}
