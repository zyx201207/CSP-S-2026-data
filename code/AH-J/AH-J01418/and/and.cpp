#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,a[N],sum=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
		cin>>a[i];
		for(ll i=1;i<=m;i++){
			sum=max(sum,a[i]&a[i+1]);
		}
	}
	cout<<sum;
    return 0;
}
