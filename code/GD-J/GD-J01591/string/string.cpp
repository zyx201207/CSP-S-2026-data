#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200001],l=1,r,daan,t;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	r=n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<r){
		t=min(a[l],a[r]);
		if(c[l]!=c[r]){
			daan+=t;
		}
		if(a[l]<=a[r]){
			c[l]=c[r];
		}
		else{
			c[r]=c[l];
		}
		a[l]-=t;
		a[r]-=t;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<daan;
	return 0;
}
