#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	long long sum=0;
	char c[200005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		
	}
	int l=0,r=n-1;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				sum+=a[r];
				a[r]=0;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				sum+=a[l];
				a[l]=0;
				l++;
			}
			else{
				sum+=a[l];
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
			
		}
		else if(a[l]!=a[r]&&c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
		}
		else {
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
}
