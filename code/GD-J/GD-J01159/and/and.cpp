#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],l=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	l=a[n];
	for(int i=n-1;i>n-m;i--){
		l=(l & a[i]);
	}cout<<l;
    return 0;
}