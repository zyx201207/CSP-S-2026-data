#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],l,r,mid,cz;
int check(int x){
	cz=0;	//cout << x << ' ';
	for(int i=1;i<=n;++i){
		if(i<=x){
			if(i==x){
				for(int j=1;j<=x;++j){
					cz=cz+a[x]-a[j];
				}
				if(cz<=m){
					//cout << cz << '\n';
					return 1;
				}
			}
		}else{
			cz-=(a[i]-a[i-x]);
			cz+=(x-1)*(a[i]-a[i-1]);
			if(cz<=m)return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	r=n;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;//,cout << mid;
	}
	cout << l;
	return 0;
}
