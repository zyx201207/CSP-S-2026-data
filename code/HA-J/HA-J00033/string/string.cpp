#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
string x;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int last=-1;
	for(int i=1;i<=n;i++)
	{
		int num;char eve;
		cin>>num>>eve;
		for(int j=0;j<num;j++)
		{
			x=x+eve;
		}
	}
	int ans=0;
	int len=x.size();
	for(int i=0;i<len/2;i++)//Õý 
	{	
		if(x[i]!=x[len-i-1])
		{
			ans++;
		}
	}
	
	//cout<<'\n';
	cout<<ans;
	return 0;
}
