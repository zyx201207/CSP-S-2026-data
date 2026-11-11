#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll n,a[N],ans;
char c[N];
void update1(ll l,ll r,ll sum){
	a[r]+=sum;
	if(a[r]>=0){
		return;
	}else{
		a[r]=0;
		update1(l,r-1,sum+a[r]);
	}
}
void update2(ll l,ll r,ll sum){
	a[l]+=sum;
	if(a[l]>=0){
		return;
	}else{
		a[l]=0;
		update2(l+1,r,sum+a[l]);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll i=1,j=n;
	while(i<=j){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				cout<<1<<" ";
				ans+=a[i];
				update1(i+1,j-1,a[j]-a[i]);
			}if(a[i]<a[j]){
				ans+=a[j];
				update2(i+1,i-1,a[i]-a[j]);
			}else{
				ans+=a[j];
				a[j]=0;
			}
		}
		i++,j--;
	}
	cout<<ans;
	return 0;
}
//3
//2 a
//2 b
//1 c
