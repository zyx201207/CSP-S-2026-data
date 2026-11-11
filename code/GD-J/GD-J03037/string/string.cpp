#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
unsigned long long ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				ans=ans+a[r];
				a[l]-=a[r];
				a[r]=0;
			}
			else{
				ans=ans+a[l];
				a[r]-=a[l];
				a[l]=0;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
			}
			else{
				a[r]-=a[l];
				a[l]=0;
			}
		}
		if(a[l]==0){
			l++;
		} 
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
