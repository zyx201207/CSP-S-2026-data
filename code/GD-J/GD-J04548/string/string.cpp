#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005];char c[200005];
int l,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int ii=1,k=1,ll=1,rr=n;
	for(int i=1;i<=l/2;i++){
		if(ii>a[ll]){
			ii=1;
			ll++;
		}
		if(k>a[rr]){
			rr--;
			k=1;
		}
		if(c[ll]!=c[rr])ans++;
		if(ll==rr)break;
	}
	cout<<ans;
}
