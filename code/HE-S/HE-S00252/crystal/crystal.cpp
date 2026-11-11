#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+50;
ll n,m;
ll a[N],sum[N];
ll w[N];
ll ans;
ll last;
bool check(int x,int pos){
	ll xy=x*(a[pos]-a[pos-1]);
	ll yy=(last-x)*a[pos-1]+m;
	yy-=(sum[pos-x-1]-sum[pos-last-1]);
	if(yy>=xy) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll mm=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		//w[i]=a[i+1]-a[i];
		sum[i]=sum[i-1]+a[i];
	}
	last=1;
	ans=1;
	for(int i=2;i<=n;i++){
		if(last*(a[i]-a[i-1])<=m){
			m-=last*(a[i]-a[i-1]);
			last++;
		}else if(a[i]-a[i-1]>mm){
			last=1;
			m=mm;
		}else{
			int l=1,r=last-1;
			int qwq=1;
			while(l<r){
				int mid=(l+r)>>1;
				if(check(mid,i)){
					qwq=mid;
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			m+=(last-qwq)*a[i-1];
			m-=(sum[i-qwq-1]-sum[i-last-1]);
			m-=(a[i]-a[i-1])*qwq;
			last=qwq+1;
		}
		ans=max(ans,last);
	}
	cout<<ans;
	return 0;
}
