#include<bits/stdc++.h>
using namespace std;
int a[9999999];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,sum=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		sort(a+1,a+n+1);
	int  sum=a[i+1]-a[i];
	ans++;
	if(a[i]=a[i+1] &&  ans<=m )
	
	sum++;
}
		cout<<sum;
return 0;
}