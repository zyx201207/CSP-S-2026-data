#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll a[200020];
char c[200020];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	int l=1,r=n;
	ll ans=0;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=min(a[l],a[r]);
			}
			a[l]-=a[r];
			r--;
		}
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=min(a[l],a[r]);
			}
			a[r]-=a[l];
			l++;
		}
		if(a[l]==a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;
			r--;
		}
	}
	
	cout<<ans<<'\n';
	
	return 0;
} 
