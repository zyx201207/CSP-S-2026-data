#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n,a[N];
char c[N];
ll ans;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r) {
		if(c[l]==c[r]&&a[l]==a[r]) {
			l++;
			r--;
		}else if(c[l]!=c[r]&&a[l]==a[r]){
			ans+=a[l];l++;
			r--;
		} else if(c[l]==c[r]&&a[l]!=a[r]) {
			if(a[l]<a[r]) {
				a[r]-=a[l];
				l++;
			}else {
				a[l]-=a[r];r--;
			}
		}else {
			if(a[l]<a[r]) {
				ans+=a[l];
				a[r]-=a[l];l++;
			}else {
				ans+=a[r];
				a[l]-=a[r];r--;
			}
		}
	} cout<<ans;
} 
