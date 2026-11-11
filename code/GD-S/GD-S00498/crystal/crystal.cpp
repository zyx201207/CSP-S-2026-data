#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_back pb
#define first fi
#define second se
int n,m,a[500005],sub[500005];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(sub[i]-sub[i-x]-(a[i]-a[i-x+1])*(i-x)<=m)return 1;
	}
	return 0;
}
int sol(){
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	if(check(r))return r;
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sub[i]=sub[i-1]+(a[i]-a[i-1])*(i-1);
	}
	cout<<sol();
	return 0;
}
