#include<bits/stdc++.h>
using namespace std;
long long n,num=0,ans=0,a[300000];
char b[300000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				a[l]=a[l]-a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]=a[r]-a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]=a[l]-a[r];
				ans+=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]=a[r]-a[l];
				ans+=a[l];
				l++;
			}
			else{
				ans+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
