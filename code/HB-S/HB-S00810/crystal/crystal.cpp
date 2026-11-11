#include<bits/stdc++.h>
using namespace std;
long long  n,m,a[500005],minn=0x3f3f3f3f,maxn,ans,p;
int check(long long x){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x) break;
		sum+=(x-a[i]);     
	}
		p=sum;
	if(sum>m){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	long long l=minn,r=0x3f3f3f3f,mid=(l+r)/2;
	
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)==0){
			l=mid+1;
			
		}
		else{
			r=mid-1;
		}
	}
	//cout<<check(l+1)<<" "<<r<<" "<<p<<" "<<m;
	for(int i=1;i<=n;i++){
		if(l<a[i] ) break;
		m-=(r-a[i]);
		ans++;
		//cout<<r-a[i]<<" "<<r<<" "<<a[i]<<endl;
		
		
	}
	cout<<ans;
	return 0;
}
