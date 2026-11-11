#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200001];
char b[200001];
long long l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long ans=0;
	l=1;
	r=n;
	while(l<r){
		if(a[l]>=a[r]){
			if(b[l]!=b[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
		}
		else{
			if(b[l]!=b[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
}

