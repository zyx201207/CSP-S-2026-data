#include<bits/stdc++.h>
using namespace std;
long long val[500050];
long long sum[500050];
long long u[500050];
long long n,m;
int ans=0;
bool check(int u){
	for(int i=u;i<=n;i++){
		if(1LL*(u-1)*val[i]-(sum[i-1]-sum[i-u])<=m){
			return true;
		} 
	}
	return false;
}
void erfen(int l,int r){
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	sort(val+1,val+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+val[i];
	}
	erfen(1,n);
	return 0;
} 
