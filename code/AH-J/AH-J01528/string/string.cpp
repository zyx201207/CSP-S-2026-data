#include<bits/stdc++.h>
using namespace std;
struct node
{
	int t;
	char c;
}a[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t>>a[i].c;
	}
	int i=1,j=n;
	while(i<j)
	{
		int mn=min(a[i].t,a[j].t);
		a[i].t-=mn;
		a[j].t-=mn;
		if(a[i].c!=a[j].c)
		{
			ans+=mn;
		}
		if(a[i].t==0)i++;
		if(a[j].t==0)j--;
	}
	cout<<ans;
	return 0;
}

