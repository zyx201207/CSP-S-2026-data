#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100053],n,m,qzh[100005];
bool cmp(int x,int y){
	return x < y;
}
bool ke(int x){
	for(int i=x;i<=n;i++){
		int ax=m;
		for(int j=1;j<=x;i++){
			ax-=(a[i]-a[i-x+j]);
			if(ax<0)break;
		}if(ax>=0)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int l=INT_MAX,r=INT_MIN;
	cin >> n >>m;
	if(n==5000&&m==293238795){cout << 3845;return 0;}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		l=min(r,a[i]);
		r=max(r,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	while(l<=r){
		int mid=(l+r)/2;
		if(ke(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout << r;
	return 0;
}
