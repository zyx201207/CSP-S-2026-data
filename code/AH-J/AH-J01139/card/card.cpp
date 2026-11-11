#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int b[200010],top;
int c[100010];
int check(int k)
{
	for(int i=1;i<=top;i++)
	    if(b[i]==k)return i;
	return -1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int j=i;j<=n;j++)
		{
			int k=a[j];
			int c=check(k);
			if(c!=-1)top=c-1;
			b[++top]=a[j];
		}
		for(int j=1;j<=top;j++)
		    c[b[j]]++;
	}
	for(int i=1;i<=m;i++)
	    cout<<c[i]<<' ';
	return 0;
}
