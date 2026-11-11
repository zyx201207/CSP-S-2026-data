#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],k,s,sum,z;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	z=a[n/2+1];
	for(int i=1;i<=n;i++){
		if(a[i]==z)
			sum++;
	}
	if(sum==n){
		cout<<sum;
		return 0;
	}
	while(m>0){
		if(a[n/2+1]-a[n/2-k]<=m){
			s=a[n/2+1]-a[n/2-k];
			m-=s;
			sum++;
		}
		k++;
	}
	cout<<sum;
	return 0;	
}
