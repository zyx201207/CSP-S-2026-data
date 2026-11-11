#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=200007;
int num[M];
signed main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","r",stdout);
	int n,j;
	long long ans=0;
	cin>>n;
	j=n;
	string str;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i]>>str[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		if(str[i]!=str[j])
		{
			ans+=min(num[i],num[j]);
		}
		j--;
	}
	cout<<ans;
	return 0;
}

