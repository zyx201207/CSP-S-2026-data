#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	int tong[100];
	cin>>n;
	int l=1,r=0,cnt=0;
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		int t=r;
		for(int j=t+1;j<=a+t;j++)
		{
			s[j]=c;
			r++;
			tong[c-96]++;
		}
	}
	while(l<=r)
	{
		if(s[l]!=s[r])
		{	
			if(tong[s[l]-96]>tong[s[r]-96])
			{
				s[r]=s[l];
				cnt++;
			}
			else
			{
				s[l]=s[r];
				cnt++;
			}
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
