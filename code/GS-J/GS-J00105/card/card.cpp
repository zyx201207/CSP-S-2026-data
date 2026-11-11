#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<a[1]+a[2]<<" "<<a[2]+a[3]<<" "<<a[3]+a[4]<<endl;
	return 0;
}
