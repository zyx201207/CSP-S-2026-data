#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int l,r;
int a[200005];
char c[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(l<r){
		if(a[l]<=a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			if(a[r]==0)r--;
			if(a[l]==0)l++;
		}
		else{
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
			if(a[r]==0)r--;
			if(a[l]==0)l++;
		}
	}
	cout<<ans;
	return 0;
}
