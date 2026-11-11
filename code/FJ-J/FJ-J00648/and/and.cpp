#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+5;
ll n,k;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll sum=a[n];
	for(int i=n-1;i>=n-k+1;i--){
		sum=sum&a[i];
	}
	cout<<sum<<endl;
	return 0;
}