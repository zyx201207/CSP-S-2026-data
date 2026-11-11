#include<bits/stdc++.h>
using namespace std;
int a;
string b;
int n;
char x;
int cnt,man;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>n>>x;
		for(int j=1;j<=n;j++)
		{
			man=b.size();
			b[man+1]=x;
		}
	}
	for(int i=0;i<b.size()/2;i++)
	{
		if(b[i]!=b[man-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}