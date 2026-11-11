#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a;
	string c;
	string b;
	int dw = 0;
	int cnt=0;
	long long minn=1005;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cin>>b[i];
		cnt++; 
		minn=min(minn,a);
		if(i!=0&&b[i]==b[0])
		{
			cnt--;
			continue;
		}
	}
	if(n==0||n==1)
	{
		cout<<0;
	}
	else if(cnt==1)
	{
		cout<<0;
	}
	else if(cnt==2)
	{
		cout<<3*minn;
	}
	else if(n==2)
	{
		cout<<minn;	
	}
	else
	{
		cout<<0;
	}
	return 0;
}
