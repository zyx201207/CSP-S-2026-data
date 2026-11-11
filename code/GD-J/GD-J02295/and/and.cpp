#include<bits/stdc++.h>
using namespace std;

int n,m;
string s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int cnt=0,ans=0;
	for(int i=0;i<n;i++)
	{
		cnt=(a[i]&a[i+1]);
		if(cnt>ans)
		{
			ans=cnt;
		}
	}
	cout <<ans;
	return 0;
 } 


