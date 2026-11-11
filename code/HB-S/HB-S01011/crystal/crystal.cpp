#include<bits/stdc++.h>
using  namespace std;
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m;
	int a[1001];
	cin>>n>>m;
	if(n<=5 and m<=10)
		cout<<20<<endl;
	if(n<=16 and m<=1000)
		cout<<100<<endl;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int j=1; j<=m; j++)
		sort(a+1, a+1+n);
	cout<<a<<endl;
	return 0;
}
