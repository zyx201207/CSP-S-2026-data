#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char c[200010]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}long long ans=0;
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else if(a[r]>a[l]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else{
				a[r]=0;
				a[l]=0;
				r--;l++;
			}
		}else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else if(a[r]>a[l]){
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else{
				ans+=a[l];
				a[r]=0;
				a[l]=0;
				r--;l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
