#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],mid=0,sum[500005],num=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	mid=(1+n)/2;
	while(m--){
		for(ll i=1;i<=n;++i){
			if(a[mid]>a[mid-i]){
				++a[mid-i];
				break;
			}
		}
	}
	for(ll i=1;i<=n;++i){
		if(a[i]==a[mid]){
			++num;
		}
	}
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=n;++j){
			if(a[j]==a[i]){
				++sum[i];
			}
		}
	}
	sort(sum+1,sum+1+n);
	cout<<max(sum[n],num);
	return 0;
}
