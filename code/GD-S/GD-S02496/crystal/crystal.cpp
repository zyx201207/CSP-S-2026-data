#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,mx=1;
ll m,a[550000],s[550000],sum;
int fnd(long long x,int l,int r){
	int i=r;
	while(l+1<r){
		int mid=l+r>>1;
		if((long long)(i-mid)*x-(s[i-1]-s[mid-1])<=m) r=mid;
		else l=mid;
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		mx=max(mx,i-fnd(a[i],0,i)+1);
	}
	cout<<mx;
}
