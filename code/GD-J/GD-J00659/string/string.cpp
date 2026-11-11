#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll a[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
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
			a[l]-=a[r];
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			r--;
		}else if(a[r]>a[l]){
			a[r]-=a[l];
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
/*

*/

