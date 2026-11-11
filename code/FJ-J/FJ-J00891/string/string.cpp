#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],z=0,l,r;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]=a[l]-a[r];
				r--;
			}if(a[l]==a[r]){
				l++;
				r--;
			}else{
				a[r]=a[r]-a[l];
				l++;
			}
		}else{
			if(a[l]>a[r]){
				z+=a[r];
				a[l]=a[l]-a[r];
				r--;
			}if(a[l]==a[r]){
				z+=a[r];
				l++;
				r--;
			}else{
				z+=a[l];
				a[r]=a[r]-a[l];
				l++;
			}
		}
	}
	cout<<z;
	return 0;
} 
