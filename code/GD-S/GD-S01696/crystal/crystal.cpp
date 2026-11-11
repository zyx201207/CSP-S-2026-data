#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+1;
ll n,m,a[N],s[N];
bool chk(int x){
	for(int r=x;r<=n;r++){
		int l=r-x+1;
		if((r-l+1)*a[r]-(s[r]-s[l-1])<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=l+r>>1;
		if(chk(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
