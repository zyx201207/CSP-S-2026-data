#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int W=2e5+5;
ll n,a[W],ans;
char c[W];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			l++;
		}else{
			while(a[l]){
				if(a[r]>a[l]){
					if(c[l]!=c[r]){
						ans+=a[l];
					}
					a[r]-=a[l];
					a[l]=0;
					l++;
					break;
				}else{
					if(c[l]!=c[r]){
						ans+=a[r];
					}
					a[l]-=a[r];
					a[r]=0;
					r--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
