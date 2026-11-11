#include<bits/stdc++.h>
using namespace std;
long long ans,l=1,r,n,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    r=n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>c[i];
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
			else if(a[l]==a[r]){
				a[l]=0;
				a[r]=0;
				l++;
				r--;
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
			else if(a[l]==a[r]){
				ans+=a[l];
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
