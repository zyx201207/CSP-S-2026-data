#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],need[500010];
int sum(int l,int r){
	return need[r]-need[l]-(a[r]-a[l])*(l-1);
}
bool check(int k){
	for(int i=1;i+k-1<=n;i++){
		if(sum(i,i+k-1)<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		need[i]=need[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l=1,r=n;
	int ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
