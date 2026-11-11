#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m;
int a[N+5];
int sum[N+5];
bool check(int x,int k){
	int ans=a[k]*(k-x)-(sum[k-1]-sum[x]);
	if(ans<=m)return true;
	return false;
}
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int mmax=1;
	for(int i=1;i<=n;i++){
		int vi=(i-1)*a[i]-sum[i-1];
		if(vi<=m){
			mmax=max(mmax,i);
		}else{
			int l=1,r=i-1,mid,ans;
			while(l<r){
				mid=(l+r)>>1;
				if(check(mid,i))r=mid;
				else l=mid+1;
				if(l==(r-1)){
					if(check(l,i)){
						ans=l;
					}else{
						ans=r;
					}
					break;
				}
			}
			mmax=max(mmax,i-ans);
		}
	}
	cout<<mmax;
	//ÎÒ°®zmj 
	return 0;
}
