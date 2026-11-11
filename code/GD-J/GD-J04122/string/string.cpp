#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char cc;
		cin>>a[i]>>cc;
		c[i]=cc-'a'+1;
	}
	int l,r;
	l=1,r=n;
	int ans=0;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else{
				l++,r--;
			}
		}
		else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else{
				ans+=a[l];
				l++,r--;
			}
		}
	}
	cout<<ans;
}
