#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll a[500010],p[500010];

bool check(int l,int r,ll m){
	return a[r]*(r-l)-(p[r]-p[l])<=m;
}

int bs(int R,ll m){
	int l=0,r=R;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid,R,m))r=mid;
		else l=mid+1;
	}
	return l;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)p[i+1]=p[i]+a[i];
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,i-bs(i,m)+1);
	}
	cout<<ans<<"\n";
}
