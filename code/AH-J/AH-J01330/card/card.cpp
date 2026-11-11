#include<bits/stdc++.h>
using namespace std;
int a[500005],c[300005],q[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	int n,m;
 	cin>>n>>m;
 	for (int i=1;i<=n;i++)
 		cin>>a[i];
 	for (int i=1;i<=n;i++)
	{
		memset(q,0,sizeof(q));
		int cnt=0;
		for (int j=i;j<=n;j++)
		{
			for (int k=1;k<=cnt;k++)
				if (q[k]==a[j])
					cnt=k-1;
			q[++cnt]=a[j]; 
		}
		for (int j=1;j<=cnt;j++)
			c[q[j]]++;
	} 
	for (int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	return 0;
} 
//10 3 3 1 2 1 3 2 3 1 2 1
