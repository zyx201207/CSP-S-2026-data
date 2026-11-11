#include<bits/stdc++.h>
using namespace std;
char a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t,cnt=0;
	cin>>t;
	while(t--)
	{
		int n;
		char x;
		cin>>n>>x;
		while(n--)
		{
			a[cnt]=x;
			cnt++;
		}
	}
	int ans=0;
	for(int i=0;i<cnt/2;i++)
	{
		if(a[i]!=a[cnt-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
