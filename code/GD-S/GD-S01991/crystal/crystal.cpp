#include<bits/stdc++.h>
//¶þ·Ö 
#define int long long
using namespace std;
const int N=5e5+10;
int n;
int m,a[N],s[N],ans;
bool check(int mid,int x,int r){
	return x*(r-mid)-(s[r-1]-s[mid-1])<=m;
}
int bs(int l,int r){
	int x=a[r],R=r;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid,x,R)){
			r=mid;
		}else l=mid+1;
	}
	return R-l+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ans=max(ans,bs(1,i));
	}
	cout<<ans;
	return 0;
}

