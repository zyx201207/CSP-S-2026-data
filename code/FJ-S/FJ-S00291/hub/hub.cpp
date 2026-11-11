#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i = 1;i<=sqrt(n)+1;i++)
		{
			if(pow(2,i)>n)
			{
				int sum = 0;
				for(int j = 1;j<=sqrt(k)+1;j++)
				{
					sum+=pow(2,j);
					if(sum>k)cout<<i-j;
					break;
				}
				break;
			}
		}
	}
	return 0;
}
