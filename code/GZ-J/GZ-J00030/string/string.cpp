//GZ-J00030 华东师范大学附属贵阳学校 张歆昀 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
int main(){
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	ll n,ans=0;
	cin>>n;
	char c[200005];
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;	
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;	
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
