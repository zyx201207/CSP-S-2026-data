#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pre[500005];
bool ck(long long x){
	for(int i=x;i<=n;i++){
		if(x*a[i]-(pre[i]-pre[i-x-1])<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;pre[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	long long l=1,r=n,mid,ans=1;
	while(l<r){
		mid=(l+r)/2;
		if(ck(mid)){
			l=mid+1;ans=mid;
		}else{
			r=mid-1;
		}
	}
	if(ck(ans+1))cout<<ans+1;
	else cout<<ans;
	return 0;
}

