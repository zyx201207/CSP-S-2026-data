#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn];
int dis[maxn];
int sum[maxn];
bool check(int len){
	for(int i=1;i+len-1<=n;i++){
		if(abs(sum[i]-sum[i+len-1])<=(len-1)*abs(sum[i+len-1]-sum[i+len])+m)
			return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) dis[i]=abs(a[i]-a[n]);
	for(int i=n-1;i>=1;i--) sum[i]=dis[i]+sum[i+1];
	int l=1,r=n,mid=(l+r)/2;
	while(l<r){
		if(check(mid)){
			l=mid;
			mid=(l+r)/2;
		}
		else{
			r=mid;
			mid=(l+r)/2;
		}
		if(mid==l) break;
	}
	if(check(r)) cout<<r;
	else cout<<l;
	return 0;
}
