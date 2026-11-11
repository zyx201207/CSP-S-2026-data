#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
} 
sort(a+1,a+n+1);
if(m==1){
	cout<<a[n];
	return 0;
}
int sum=a[n];
for(int i=2;i<=m;i++){
	sum&=a[n-i+1];
}
cout<<sum;
return 0;
}
