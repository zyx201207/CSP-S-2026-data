#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	string s;
	string y;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int q;
		char t;
		cin>>q;
		cin>>t;
		cnt+=q;
		for(int j=1;j<=q;j++)
		{
			s+=t;
			y+=t;
		}
	}
	reverse(s.begin(),s.end());
	int num=0;
	for(int i=0;i<cnt/2;i++)
	{
		if(y[i]!=s[i])num++;
	}
	cout<<num;
	return 0;
}
