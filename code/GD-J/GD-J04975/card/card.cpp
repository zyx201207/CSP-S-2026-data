#include <bits/stdc++.h>
using namespace std;
int n,a[500002],b[300002],c[500002],d[300002],k,m;
void check(int x,int n)
{
	for (int i = x;i <= n;i++)
	{
		if (b[a[i]]>1){
			for (int j = n;j>=i;j--){
				if (a[j]==a[i]){
					m=j;
					b[a[i]]--;
					break;
				}
			}
			i=m;
		}
		c[a[i]]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n>>k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	for (int i = 1;i <= k;i++){
		d[i]=b[i];
	}
	for (int i = 1;i<=n;i++){
		check(i,n);
	for (int i = 1;i <= k;i++){
		b[i]=d[i];
	}
	}
	for(int i = 1;i<=k;i++) cout << c[i]<<" ";
	return 0;
}
