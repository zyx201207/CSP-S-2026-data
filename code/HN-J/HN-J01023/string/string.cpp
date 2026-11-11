#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[1000010];
char c[1000010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
	}
	int ans=0,l=1,r=n,t=0,t1=0;
	while(l<=r){
		if(a[l]-t>a[r]-t1){
			if(c[l]!=c[r]){
				ans+=a[r]-t1;
			}
			t+=a[r]-t1;
			r--;
			t1=0;
		}else if(a[l]-t<a[r]-t1){
			if(c[l]!=c[r]){
				ans+=a[l]-t;
			}
			t1+=a[l]-t;
			l++;
			t=0;
		}else if(a[l]-t==a[r]-t1){
			if(c[l]!=c[r]){
				ans+=a[r]-t1;
			}
			l++;
			r--;
			t=0;
			t1=0;
		}
	}
	cout<<ans;
	return 0;
}
