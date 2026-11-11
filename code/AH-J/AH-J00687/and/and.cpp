#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x,sum,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
    sort(a+1,a+n+1);
    sum=a[n];
    for(int i=n-1;i>n-m;i--){
		sum&=a[i];
	}
	cout<<sum;
    return 0;
}
