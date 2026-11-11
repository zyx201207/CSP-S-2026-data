#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long maxa=-1000000000001;
long long a[500001];
long long xx(long long l,long long r){
	long long zo=0;
	for(long long i=l;i<=r-1;i++){
		zo+=a[r]-a[i];
	}
	return zo;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	sort(a+1,a+1+n);
	long long l=1,r=1;
	long long ans=0;
	while(l<=r&&l<=n&&r<=n){
		long long zong=xx(l,r);
		if(zong<=m){
			ans=max(ans,r-l+1); 
			r++;
		}else{
			l++;
			if(l>r){
				r++;
			}
		}
	}
	cout<<ans<<endl;
}

