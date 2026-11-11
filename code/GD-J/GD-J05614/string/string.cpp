#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0,z=0;
	cin>>n;
	int a[n];
	char c[n];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		z+=a[i];
	}
	int r=1,l=n;
	for(int i=1;i<=n;i++){
		if(c[l]!=c[r]){
			s+=min(a[l],a[r]);
			if(a[l]>a[r]){
				c[r]=c[l];
				a[l]-=a[r];
				r++;
			}
			else if(a[r]>a[l]){
				c[l]=c[r];
				a[r]-=a[l];
				l--;
			}
			else {
				c[l]=c[r];
				r++;
				l--;
			}
		}
		else {
			if(a[l]>a[r]){
				a[l]-=a[r];
				r++;
			}
			else if(a[r]>a[l]){
				a[r]-=a[l];
				l--;
			}
			else {
				r++;
				l--;
			}
		}
		
	}
	cout<<s<<" ";
	return 0;
} 
