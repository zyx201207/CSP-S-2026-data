#include<bits/stdc++.h>
using namespace std; 
int n;
long long  m;
const int N=5e5+10;
long long  a[N],s[N];
long long  ans;
bool chk(int l,int r){
	if(l==r){
		return 1;
	}
	long long  k=0; 
	k=(a[r]-a[r-1])*(r-l+1);
	k-=(a[r]-a[l-1]);
	return k<=m;
}
long long max(long long a,int b){
	return a>b?a:b;
}
int main(){ 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+a[i];
	}
	for(int l=1,r=1;l<=n;l++){
		while(chk(l,r)&&r<=n&&l<=n){
			r++;
		}
		ans=max(ans,r-l);
	}
	cout<<ans<<"\n";
	return 0;
} 
