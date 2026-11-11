#include<bits/stdc++.h>
using namespace std;
long long T,t[100001],cnt;
char c[100001],M[256]; 
int check(int n)
{
	long long l=1,r=n,ans=0;
	while(l>n&&r<1)
	{
		if(c[l]!=c[r])
		{
			if(t[l]!=0&&t[r]!=0)
			{
				t[l]-=min(t[l],t[r]);
				t[r]-=min(t[l],t[r]);
			}
			if(t[l]==0)
			{
				l++;
			}
			if(t[r]==0)
			{
				r--;
			}
		}
		else
		{
			cnt+=min(t[l],t[r]);
			t[l]-=min(t[l],t[r]);
			t[r]-=min(t[l],t[r]);
			l++;
			r--;
		}
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	string b;
	for(long long i=1;i<=T;i++)
	{
		cin>>t[i]>>c[i];
		if(c[i]==c[i-1])
		{
			t[i-1]+=t[i];
			t[i]=0;
		}
	}
	check(1);
	long long ant=0;
	for(long long i=1;i<=T;i++)
	{
		if(t[i]!=0)
		{
			ant+=t[i];
		}
	}
	cout<<ant/2+cnt;
}
