#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m,a[N],ma,s[N],t,wi,ans;
bool check(int mid,int x){
	if(x==1){
		if(t>a[mid]){
			return false;
		}
		return true;
	}else{
		if(s[wi]-s[mid-1]-t*(wi+1-mid)<=m){
			return true;
		}
		return false;
	}
}
int fen(int z,int y,int x){
	int mid;
	while(z<y){
		if(x==1)
			mid=(z+y+1)/2;
		else
			mid=(z+y)/2;
		if(check(mid,x)){
			if(x==1)
				z=mid;
			else
				y=mid;
		}else
			if(x==1)
				y=mid-1;
			else
				z=mid+1;
	}
	return z;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i]=ma-a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) continue;
		t=a[i];
		wi=fen(1,n,1);
		int ti=fen(1,n,2);
		ans=max(ans,wi-ti+1);
	}
	cout<<ans;
	return 0;
} 
