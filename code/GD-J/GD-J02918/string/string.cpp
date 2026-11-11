#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)	cin>>a[i]>>c[i];
	ll l=1,r=n;
	while(l<=r){
		if(a[l]<=a[r]){
			if(c[l]!=c[r])	ans+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l++;
		}else{
			if(c[l]!=c[r])	ans+=a[r];
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
