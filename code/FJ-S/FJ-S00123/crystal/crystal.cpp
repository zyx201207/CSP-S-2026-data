#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll sum[500005];
int ans;
bool check(int num,int i){
	return (i-num+1)*a[i]-sum[i]+sum[num-1]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i = 1;i<=n;i++){
		int l = 1,r = i;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				r=mid;
			}
			else{
				l=mid+1; 
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;	
}
