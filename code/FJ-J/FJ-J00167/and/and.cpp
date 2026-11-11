#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			k=i;
			break;
		}
	}
	sort(a,a+n);
	int sum1=a[n-1];
	int sum2=a[k];
	for(int i=n-2;i>=m-1;i--)
	{
		sum1&=a[i];
	}
	for(int i=k+1;i<m;i++)
	{
		sum2&=a[i];
	}
	cout << max(sum1,sum2);
	return 0;
}
