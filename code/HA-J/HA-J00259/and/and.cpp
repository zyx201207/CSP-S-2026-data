#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],maxm=-0x3fffffff;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=2000){
		for(int i=1;i<=n;++i){
			ll sum=a[i];
			for(int j=1;j<m;++j){
				sum&=a[i+j];
			}
			maxm=max(maxm,sum);
		}
		cout<<maxm;
	}else if(m==n-1){
		ll sum1=a[1];
		for(int i=2;i<=m;++i){
			sum1&=a[i];
		}
		ll sum2=a[n];
		for(int i=n-1;i>1;--i){
			sum2&=a[i];
		}
		cout<<max(sum1,sum2);
	}else{
		sort(a+1,a+1+n,cmp);
		ll sum=a[1];
		for(int i=2;i<=m;++i){
			sum&=a[i];
		}
		cout<<sum;
	}
	return 0;
}

