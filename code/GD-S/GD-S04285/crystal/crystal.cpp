#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],r,l,mid,b[500005],x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	l=a[1],r=a[n];
	while(l<=r)
	{
		mid=(l+r)/2;
		long long s=0;
		for(int j=1;a[j]<=mid;j++)
			s+=abs(a[j]-mid);
		if(s<=m)l=mid+1;
		if(s>m)r=mid-1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=l)x++;
		else break;
	}
	cout<<x;
	return 0;
} 
