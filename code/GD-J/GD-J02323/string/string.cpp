#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int lum=0,ans=0,rum=0,pot=0;
	int l=1,r=n;
	if(a[1]>a[n]){
		l++;
		lum=a[1];
	}
	else{
		r--;
		rum=a[n];
	}
	while(l<=r){
		if(lum<=rum){
			if(c[l]!=c[r+1]){
				if(lum+a[l]<=rum){
					ans+=a[l];
				}
				else{
					ans+=rum-pot;
				}
			}
			pot=min(rum,lum+a[l]);
			lum+=a[l];
			l++;
		}
		else{
			if(c[l-1]!=c[r]){
				if(rum+a[r]<=lum){
					ans+=a[r];
				}
				else{
					ans+=lum-pot;
				}
			}
			pot=min(rum+a[r],lum);
			rum+=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
