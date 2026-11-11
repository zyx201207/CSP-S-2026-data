#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//ios::sycn_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m,a[1000005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-2];
	return 0;
}
