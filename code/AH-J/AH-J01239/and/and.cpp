#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
long long an;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	an=a[n-1];
	for(long long i=n-2;i>n-1-m;i--){
		an=an&a[i];
	}
	cout<<an;
    return 0;
}
