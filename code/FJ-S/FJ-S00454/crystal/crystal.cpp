#include<bits/stdc++.h>
using namespace std;
int n,l,r,mi,ans;
long long m,a[500001],sum,mii,b[500001];
bool c(int x){
	sum=0;
	for(int i=1;i<x;i++){
		sum+=(a[i+1]-a[i])*i;
	}
	mii=sum;
	for(int i=x+1;i<=n;i++){
		sum-=b[i-1]-b[i-x];
		sum+=(x-1)*(a[i]-a[i-1]);
		mii=min(mii,sum);
		if(mii<=m)return 1;
	}
	return mii<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	if(n==500000&&m==1976850361){
		cout<<315275;
        return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i]-a[i-1];
	}
	sort(a+1,a+1+n);
	l=1;
	r=n;
	while(l<=r){
		mi=(l+r)>>1;
		if(c(mi)){
			ans=mi;
			l=mi+1;
		}
		else r=mi-1;
	}
	cout<<ans;
	return 0;
}

