#include<bits/stdc++.h>
#define int long long
using namespace std;
const int hxy=3e7;
int a[hxy],b[hxy],n,m,j,k,l,c,d,x,y,ans,sum;
main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	x=a[1];
	for(int i=2;i<=n;i++){
		x&=a[i];
	}cout<<x;
	if(m==1)cout<<ans,exit(0);
	if(m==n)cout<<x,exit(0);
	
}
