#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 500005;
ll n,m,a[MAXN],f[MAXN],cf[MAXN],ans;
bool judge(int x){
	for(int l=1;l+x-1<=n;l++){
		if(f[l+x-1]-f[l]-(l)*(a[l+x-1]-a[l])<=m){
			return true;
		}
	}
	return false;
}
int devide(int l,int r){
	if(l>=r){
		return l;
	}
	int mid=(l+r)/2+1;
	if(!judge(mid)){
		return devide(l,mid-1);
	}
	else{
		return devide(mid,r);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+i*cf[i];
	}
	ans=devide(1,n);
	cout<<ans;
	return 0;
}
