#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
		if(c[l]!=c[r]){
			if(a[l]>=a[r]){
				ans+=a[r];
				a[l]=a[l]-a[r];
				r--;
			}else{
				ans+=a[l];
				a[r]=a[r]-a[l];
				l++;
			}
		}else{
			if(a[l]>=a[r]){
				a[l]=a[l]-a[r];
				r--;
			}else{
				a[r]=a[r]-a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
