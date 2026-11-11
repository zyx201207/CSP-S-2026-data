#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],sum[500005];
bool check(int x,int y){
	long long po=sum[y]-sum[x-1],op=a[y]*(y-x+1);
	if(op-po<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
