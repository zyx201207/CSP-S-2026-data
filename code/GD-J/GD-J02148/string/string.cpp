#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
int js=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			if(a[l]==a[r]){
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				js+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			if(a[l]<a[r]){
				js+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			if(a[l]==a[r]&&l!=r){
				js+=a[l];
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}
	}
	cout<<js;
	return 0;
}
