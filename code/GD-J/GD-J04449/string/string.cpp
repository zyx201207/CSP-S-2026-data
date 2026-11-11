#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],sum,l,r,ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	l=1;
	r=n;
	while(sum>1){
		if(l==r) break;
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			sum-=(2*a[r]);
			a[l]-=a[r];
			r--;
		}
		else{
			if(c[l]!=c[r]) ans+=a[l];
			sum-=(2*a[l]);
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
