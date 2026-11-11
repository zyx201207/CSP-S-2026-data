#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,l,ma=0;
	string b[200001],a;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>b[i];
		l=0;
		for(int j = 0;j <= b[i].size()-1;j++)
		{
			l = l*10+b[i][j]-'0';
		}
		for(int j = i-1;j >= 1;j--)
		{
			if(b[i] == b[j])
			{
				ma = max(ma,l);
			}
		}
	}
	cout<<ma;
	return 0;
} 
