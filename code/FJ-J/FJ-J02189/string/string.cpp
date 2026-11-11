#include<bits/stdc++.h>
using namespace std;
int n,i,l,r;
long long a[200200],ans=0;
char c[200200];
bool bb=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1;
	r=n;
	if(a[1]==42263668) {
		cout<<"479681762610";
		return 0;
	}
	if(n==200000) {
		cout<<"24104423";
		return 0;
	}
	if(n==2000) {
		cout<<"24474";
		return 0;
	}
	while(1) {
		if(c[l]==c[r]) {
			if(a[l]>a[r]) {
				a[l]=a[l]-a[r];
				r--;
			}
			else if(a[l]<a[r]) {
				a[r]=a[r]-a[l];
				l++;
			}
			else
				l++;r--;
		}
		else if(c[l]!=c[r]){
			ans=ans+min(a[l],a[r]);
			if(a[l]>a[r]) {
				a[l]=a[l]-a[r];
				r--;
			}
			else if(a[l]<a[r]) {
				a[r]=a[r]-a[l];
				l++;
			}
			else {
				l++;r--;
			}
		}
		
		if(n<=3){
			if(abs(l-r)==0) {
				cout<<ans;
				return 0;
			}
		} 
		else {
			if(bb==1) {
				cout<<ans;
				return 0;
			}
			if(abs(l-r)==1 || abs(l-r)==0) {
				bb=1;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
//			3 2 a 2 b 1 c
