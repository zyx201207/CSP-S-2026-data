#include<bits/stdc++.h> 
using namespace std;
int n,mx;
long long m,a[500005],s[500005];
bool g(int l,int x){
	long long sx=s[x]-s[l-1],sy=a[x]*(x-l+1);
	if(sx<0){
		if(sx+1e18<sy){
			return 0;
		}
	}
	if(sy-sx>m){
		return 0;
	}
	return 1;
}
int f(int l,int r){
	int mid,ans=0,ll=l;
	while(l<=r){
		mid=(l+r)/2;
		if(g(ll,mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	for(int i=1;i<=n;i++){
		mx=max(mx,(f(i,n)-i+1));
		
	}
	cout<<mx;
	return 0;
}
