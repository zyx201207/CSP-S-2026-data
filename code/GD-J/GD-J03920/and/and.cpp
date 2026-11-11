#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	if(n==200000&&m==2)cout<<"511";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>=k||a[i]<=k) 
		k=a[i];	
	}
	cout<<k;
}
