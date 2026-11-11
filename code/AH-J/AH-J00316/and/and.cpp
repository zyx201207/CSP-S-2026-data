#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20005],t,mx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	sort(a+1,a+n+1);
	t=a[n];
	for(long long i=n-1;i>n-m;i--){
		t=(t&a[i]);
	}
	cout<<t;
	return 0;
}
