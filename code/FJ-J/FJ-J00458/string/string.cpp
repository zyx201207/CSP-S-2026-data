#include<bits/stdc++.h>
using namespace std;
string a;
long long n,ans=0,m[20050],zong=0;
char b[20050];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long z=1;z<=n;z++)
	{
		cin>>m[z];
		cin>>b[z];
	}
	long long l=1,r=n;
	while(l!=r)
	{
		if(b[l]==b[r])
		{
			if(m[l]>=m[r])//可能有问题 
			{
				m[l]-=m[r];
				m[r]=0;
				r--;
			}
			else
			{
				m[r]-=m[l];
				m[l]=0;
				l++;
			}
		}
		else
		{
			if(m[l]>=m[r])
			{
				m[l]-=m[r];
				ans+=m[r];
				m[r]=0;
				r--;
			}
			else
			{
				m[r]-=m[l];
				ans+=m[l];
				m[l]=0;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
