#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char c[200010];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=1;
	while(l+r<=n){
		if(c[l]==c[n+1-r]){
			if(a[l]<a[n+1-r]){
				a[n+1-r]-=a[l];
				a[l]=0;
				l++;
			}else{
				a[l]-=a[n+1-r];
				a[n+1-r]=0;
				r++;
				if(a[l]==0) l++;
			}
		}else{
			if(a[l]<a[n+1-r]){
				a[n+1-r]-=a[l];
				ans+=a[l];
				a[l]=0;
				l++;
			}else{
				a[l]-=a[n+1-r];
				ans+=a[n+1-r];
				a[n+1-r]=0;
				r++;
				if(a[l]==0) l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
