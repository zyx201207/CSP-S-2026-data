#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
unsigned long long s=0,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		s+=a[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>=a[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else{
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
		if(c[l]!=c[r]){
			if(a[l]>=a[r]){
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
