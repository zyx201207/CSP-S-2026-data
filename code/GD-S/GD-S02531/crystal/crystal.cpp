#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],d,t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (long long i=1;i<=n;i++){
		d=a[i+1]-a[i];
		if ((t+d*i)<=m){
			t+=d*i;
		}
		else {
			cout<<i;
			return 0;
		}
	}
	return 0;
}
