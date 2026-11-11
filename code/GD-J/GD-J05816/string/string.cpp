#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=0;
	char c;
	string ju;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			ju+=c;
		}
	}
	for(int i=(ju.length()+1)/2;i>=0;i--)
	{
		if(ju[i]!=ju[(ju.size()+1)/2-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;


	
}
