#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=0,i=2;
	do{
		for(long long j=1;j<i;j++)
			ans+=a[i]-a[j];
		i++;
	}while(ans<m);
	i--;
	while(a[i+1]==a[i])
		i++;
	cout<<i;
}
