#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n;
	cin>>n;
	long long a[200009]={};
	char b[200009]={};
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=1,r=n,ans=0;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
				continue;
			}
			if(a[l]==a[r]){
				ans+=a[l];
				a[l]=a[r]=0;
				l++;
				r--;
				continue;
			}
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				r--;
				continue;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
				continue;
			}
			if(a[l]==a[r]){
				l++;
				r--;
				continue;
			}
			if(a[l]<a[r]){
				a[r]-=a[l];
				r--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
} 
