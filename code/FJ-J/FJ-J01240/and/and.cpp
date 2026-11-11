#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200020];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	ans=a[n];
	for(long long i=n-1;i>=m;i--){
		ans&=a[i];
		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
