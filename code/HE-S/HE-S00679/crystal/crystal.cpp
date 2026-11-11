#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,sum,j;
int s(long long x){
	 sum=0;
	for(int i=j;i<=n;i++){
		sum+=x-min(x,a[i]);
	}	
//	return sum;
}
long long er(){
    long long l=-0x3f3f3f,r=1e12;
    while(l+1<r){
    	long long mid=(l+r)>>1;
        s(mid);
    	if(sum<=m)l=mid;
    	else r=mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=5000){
	sort(a+1,a+n+1);
	for(j=0;j<=n;j++){
		long long ans1=0;
		long long e=er();
//     	cout<<e;
	for(int i=j;i<=n;i++){
		if(a[i]<=e)ans1++;
	}
	ans=max(ans,ans1);
	}
	cout<<ans;}
	else{
		long long e=er();
//     	cout<<e;
	for(int i=j;i<=n;i++){
		if(a[i]<=e)ans++;
	}
	cout<<ans;
	}
	return 0;
}
