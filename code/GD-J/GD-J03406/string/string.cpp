#include <bits/stdc++.h>
using namespace std;
string s;
long long cnt,n,sum;

void volue()
{
	int r=sum-1;
	for(int i=0;i<sum;i++)
	{
		if(i>=r) break;
		
		if(s[i] != s[r])
		{
			cnt++;
		}
		r--;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;char c;
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	volue();
	cout<<cnt;
	return 0;
}
