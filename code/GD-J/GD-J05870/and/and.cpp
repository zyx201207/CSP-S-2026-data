#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
int n,m,i;
long long maxi;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n%2==1) n=n+1;
	cout<<a[n/2];
	return 0;
}
