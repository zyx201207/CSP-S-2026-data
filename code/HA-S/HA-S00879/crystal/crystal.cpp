#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[2000009],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll summ=0;
	for(ll i=1,j=1;i<=n;i++){
		summ+=(i-j)*(a[i]-a[i-1]);
		while(summ>m){
			summ-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

