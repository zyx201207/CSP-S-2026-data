#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500010],sum[500010];
bool chk(int x,int i){
	int summ=sum[i]-sum[x-1];
	int k=i-x+1;
	int need=a[i]*k-summ;
	if(m>=need){
		return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	for(int i=2;i<=n;i++){
		int l=1,r=i,ans_1=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(chk(mid,i)){
				ans_1=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-ans_1+1);
	}
	cout<<ans;
	return 0;
}