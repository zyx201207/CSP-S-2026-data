#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300010];
int b[500010];
int c[300010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		a[b[i]]=i;
	for(int i=n;i>=1;i--)
	{
		int j=i;
		while(j<=n){
			c[b[j]]++;
			if(a[b[j]]<=j) j++;
			else j=a[b[j]]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}
