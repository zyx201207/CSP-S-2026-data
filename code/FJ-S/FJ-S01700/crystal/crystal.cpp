#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],b[N];
bool check(int len){
	ll ans=-1;
	for(int i=len;i<=n;i++){
		ll res=b[i]-b[i-len+1]-(a[i]-a[i-len+1])*(ll)(i-len);
		if(ans==-1||res<ans) ans=res;
	}
	if(ans<=m) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 
