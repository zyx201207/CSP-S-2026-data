#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int N=5e5+5;
ll m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);

		bool test_a=1,test_b=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				test_a=0;
				break;
			}
		}
		for(int i=2;i<n;i++){
			if(a[i]-a[i-1]!=a[i+1]-a[i]){
				test_b=0;
				break;
			}
		}
		if(test_a){
			int maxn=-2e9;
			for(int i=2;i<=n;i++){
				int l=0,r=i;
				while(l+1<r){
					int k=(l+r)>>1;
					if((ll)k*(k-1)/2<=m){
						l=k;
					}else{
						r=k;
					}
				}
				maxn=max(maxn,l);
			}
			cout<<maxn;
			return 0;
		}
		if(test_b){
			int maxn=-2e9;
			ll d=a[2]-a[1]; 
			for(int i=2;i<=n;i++){
				int l=0,r=i;
				while(l+1<r){
					int k=(l+r)>>1;
					if((ll)k*(k-1)/2<=m/d){
						l=k;
					}else{
						r=k;
					}
				}
				maxn=max(maxn,l);
			}
			cout<<maxn;
			return 0;
		}
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];
		}
		ll maxn=-2e9;
		for(int i=2;i<=n;i++){
			ll l=0,r=i;
			while(l+1<r){
				ll k=(l+r)/2;
				if(a[i]*k-(s[i-1]-s[i-k-1])<=m){
					l=k;
				}	else{
					r=k;
				}
			}
			maxn=max(maxn,l);
		}
		cout<<maxn+1;
	
	return 0;
}
