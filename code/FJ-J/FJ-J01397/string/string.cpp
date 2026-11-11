#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],l,r,s;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]<a[r]){
				s+=a[l];
				b[l]=b[r];
			}
			else{
				s+=a[r];
				b[r]=b[l];
			}
		}
		if(a[l]<a[r]){
			a[r]=a[r]-a[l];
			l++;
		}
		else if(a[l]>a[r]){
			a[l]=a[l]-a[r];
			r--;
		}
		else{
			l++;
			r--;
		}
	}
	cout<<s;
	return 0;
}
