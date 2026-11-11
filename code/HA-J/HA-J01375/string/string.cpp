#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long ans=0;
	for(int i=0;i<n;i++){
		long long g;
		char c;
		cin>>g>>c;
		a[i]=g;
		s+=c;
	}
	long long l=0,r=n-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans+=min(a[l],a[r]);
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
			else{
				a[r]=0;
				a[l]=0;
				l++;
				r--;
			}
		}
		else{
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
			else{
				a[r]=0;
				a[l]=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
