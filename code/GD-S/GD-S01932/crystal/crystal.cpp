#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5*1e5+10;
ll n,m;
ll a[N];
ll c[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<N){
		ll sum;
		for(int i=n;i>=1;i--){
			ll k=a[i];
			sum=0;
			for(int j=i;j>=1;j--){
				if(m>=abs(k-a[j])){
					m-=abs(k-a[j]);
					sum+=k;
				}else{
					j=0;
				}
			}
		} 
		cout<<sum;
	}else{
		ll k=a[n];
		ll sum=0;
		for(int i=n;i>=1;i--){
			if(m>=k-a[i]){
				m-=(k-a[i]);
				sum+=k;
			}else{
				break;
			}
		}
		cout<<sum;
	}
	return 0;
}
