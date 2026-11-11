#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long a[200005];
bool cmp(long long cc,long long dd){
	return cc>dd;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		ans=-99999;
		for(int i=1;i<=n;i++){
			long long x;
			cin>>x;
			ans=max(x,ans);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i]&a[j];
				ans=max(ans,x);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		cin>>a[1];
		ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	long long pan=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) pan=1;
	}
	if(pan==0){
		cout<<n-m;
		return 0;
	}else{
		sort(a+1,a+n+1,cmp);
		cout<<a[n-m+1];
		return 0;
	}
	
}
