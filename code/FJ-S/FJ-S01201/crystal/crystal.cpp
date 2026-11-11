#include<bits/stdc++.h>
#define int long long
#define unint unsigned long long
using namespace std;
const int SIZE=5000005;
int n,m,a[SIZE],ans=-1e18;
bool f(int x){
	int sum=0;
	for(int i=x-1;i>=1;i--){
		sum+=(a[x]-a[i]);
		if(i!=1){
			if(sum>m){
				ans=max(ans,x-i);
				return 0;
			}else if(sum==m){
				ans=max(ans,x-i+1);
				return 0;
			}
		}else{
			if(sum>m){
				ans=max(ans,x-i);
				return 0;
			}else if(sum==m){
				ans=max(ans,x-i+1);
				return 1;
			}
		}
	}
	return 1;
} 
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int l=1,r=n;
	int mid=(l+r)>>1;
	while(l<r){
		if(f(mid)){
			l=mid+1;
		}else r=mid;
		mid=(l+r)>>1;
	}
	f(mid);
	f(1),f(n);
	cout<<ans;
	return 0;
}

