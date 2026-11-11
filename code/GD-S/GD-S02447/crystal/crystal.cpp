#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100];
long long r[500100];
bool check(int mid){
	for(int i=1;i<=n;i++) r[i]=0;
	for(int i=1;i<mid;i++){
		r[mid]+=a[mid]-a[i];
	}
	for(int i=mid+1;i<=n;i++){
		r[i]=r[i-1]-(a[i-1]-a[i-mid])+(mid-1)*(a[i]-a[i-1]);
//	  	cout<<a[i-1]-a[i-mid]<<" "<<a[i-1]<<" "<<a[i-mid]<<endl; 
	}
	for(int i=mid;i<=n;i++) if(r[i]<=m) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+n+1);
//	cout<<1;
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r<<endl;
	fclose(stdin);
	fclose(stdout);
}//4:01
