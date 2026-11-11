#include<bits/stdc++.h>
using namespace std;
long long n,m,z,sum=1,j;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	z=a[n];
	j=1;
	for(long long i=1;i<=m;i++){
		if(a[1]==z)break;
		else if(a[n-j]==z){
			j++;
			a[n-j]++;
		}
		else if(a[n-j]<z)a[n-j]++;
	}
	for(long long i=1;i<=n;i++)if(a[i]==a[i-1])sum++;
	cout<<sum;
	return 0;	
}
