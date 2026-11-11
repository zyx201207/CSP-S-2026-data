#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500010],m,b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		b[i]=b[i-1]+((long long)i-1LL)*(a[i]-a[i-1]);
	}
	int l=1,r=n+1;
	while(l+1!=r){
		int mid=(l+r)/2;
		long long u=1e18;
		for(int i=mid;i<=n;i++){
			u=min(u,b[i]-b[i-mid]-(a[i]-a[i-mid])*((long long)i-(long long)mid));
		}
		if(u<=m){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l<<endl;
	return 0;
}
