#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],t[300005],num[300005];
signed main() {
 	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)	cin>>a[i];
	for(int i=n;i>=1;i--)
		if(num[a[i]]==0)	num[a[i]]=i;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			t[a[j]]++;
			j=num[a[j]];
		}
	for(int i=1;i<m;i++)	cout<<t[i]<<' ';
	cout<<t[m]<<"\n";
	return 0;
}
