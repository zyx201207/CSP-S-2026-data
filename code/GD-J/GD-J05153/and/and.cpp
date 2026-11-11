#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],x;
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
sort(a,a+n);
if(m==1) {cout<<a[n];}
else if(m==2) 
{
cout<<max((a[n]&a[n-1]),(a[n-1]&a[n-2]));
}
else 
{
for(int i=1;i<=m;i++)
{
x=max(max(x,(a[n]&a[n-i])),(a[n-i]&a[n-i-1]));
}
cout<<x;
}
	return 0;
} 
