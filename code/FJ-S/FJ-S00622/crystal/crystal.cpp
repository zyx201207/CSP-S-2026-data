#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
bool check(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(i>=x){
			if(sum+m>=a[i]*x){
				return 1;
			}
			sum-=a[i-x+1];
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n,mid,ans=0;
	while(l<r){
		//cout<<l<<" \n";
		mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
