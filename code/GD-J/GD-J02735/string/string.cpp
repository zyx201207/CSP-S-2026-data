#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200002];
char c[200002];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,L=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	int ans=0;
	for(int l=1,r=n;l<r;){
		if(a[l]<a[r]){
			ans+=(c[l]!=c[r])*a[l];
			a[r]-=a[l];
			l++;
		}else if(a[l]>a[r]){
			ans+=(c[l]!=c[r])*a[r];
			a[l]-a[r];
			r--;
		}else{
			ans+=(c[l]!=c[r])*a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
