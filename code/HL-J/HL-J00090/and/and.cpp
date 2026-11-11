#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,sum;
int main(){
	freopen("and.in","r",stdin);
	freopem("and.out"."w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	sum=a[n];
	for(int i=1;i<=m;i++){
		sum=sum&a[n-i];
	}
	cout<<sum;
	return 0;
}
