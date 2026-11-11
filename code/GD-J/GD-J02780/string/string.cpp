#include<bits/stdc++.h>
using namespace std;
int n,sum;
string s;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int d;
		char c;
		cin>>d;
		cin>>c;
		for(int g=0;g<d;g++)
		{
			s[sum]=c;
			sum++;
		}
	}
	int t=sum,ans=0;
	
		for(int i=0;i<sum/2;i++)
		{
			if(s[i]!=s[sum-i-1])
			{
				ans++;
			}
		}
		cout<<ans;
	return 0;
}
