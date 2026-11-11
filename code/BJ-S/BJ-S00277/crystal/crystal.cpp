#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
ll n,m,a[N],sum[N],ans=-N;
int check(int x){
	int l=1,r=x,tmp=-N;
	while(l<=r){
		int mid=(l+r)/2;
		int len=x-mid;
		ll t1=a[x]*len-(sum[x-1]-sum[mid-1]);
		if(t1<=m){
			tmp=max(tmp,len+1);
			r=mid-1;
		}else l=mid+1;
	}
	return tmp;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int tmp=check(i);
		//cout<<tmp<<" ";
		ans=max((int)ans,tmp);
	}
	cout<<ans;
    return 0;
}
