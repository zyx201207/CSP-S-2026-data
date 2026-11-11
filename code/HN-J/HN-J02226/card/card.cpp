#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],c[500005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i];
	for(int i = 1;i<=n;i++)
	{
		int b[300005] = {0},c[500005]={0};
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
			if(b[a[j]]>1)
			{
				for(int k=i;k<=j;k++) c[k]=1;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(c[j]!=1) cout << a[j] << ' ';
		}
	 } 
}
