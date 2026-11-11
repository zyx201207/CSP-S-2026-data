#include <bits/stdc++.h>
using namespace std;
int n=0;
int m=0;
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	vector<int>a(n);
	vector<int>b(n-1);//差值 
	vector<int>c(n);//差值前缀和 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i) b[i-1]=a[i]-a[i-1];
		if(i) c[i]=c[i-1]+b[i-1];
	}
	int d[n][n];
	int maxnum=-1;
	int f=0;
	while(1)
	{
		int e=0;
		while(e<n&&(c[e]-c[f])<=m) e++;
		
	}
	
	cout<<maxnum<<endl;
	return 0;
} //THE END
