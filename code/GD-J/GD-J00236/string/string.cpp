#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n;
long long a[200005];
char c[200005];
long long ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<n){
		if(a[l]>a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else{
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
		}else if(a[r]>a[l]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else{
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}else{
			if(c[l]==c[r]){
				a[r]=0;
				a[l]=0;
				l++,r--;
			}else{
				ans+=a[r];
				a[r]=0;
				a[l]=0;
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
