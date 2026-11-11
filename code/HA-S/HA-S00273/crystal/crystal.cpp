#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],ans=1;
unsigned long long m;
int sum[500005];
bool cmp(int x,int y){
	return x<y;
}
bool check(int x,int id){
	if(m>=((id-x)*a[id]-(sum[id-1]-sum[x-1])))return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				ans=max(ans,i-mid+1);r=mid-1;
			}else{l=mid+1;}
		}
	}
	cout<<ans;
	return 0;
} 
