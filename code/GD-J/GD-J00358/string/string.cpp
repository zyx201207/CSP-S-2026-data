#include<bits/stdc++.h>
using namespace std;
char st[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int x;
	int long_=0;
	for(int i=1;i<=n;i++)
	{
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++)
		{
			st[long_+j]=a;
		}
		long_+=x;
	}
	int half;
	if(long_&1==1)
	{
		half=(long_-1)/2;
	}
	else
	{
		half=long_/2;
	}
	int cnt=0;
	int j=long_;
	for(int i=1;i<=half && j>=(long_-half);i++)
	{
		if(st[i]!=st[j])
		{
			cnt++;
		}
		j--;
	}
	cout<<cnt<<'\n';
	return 0;
}
