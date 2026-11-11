#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	longlong n,m,a[10005],sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum=a[0];
	}
	for(int i=1;i<=m;i++){
		sum+=sum&a[i];
	}
	cout<<sum;
	return 0;
}
