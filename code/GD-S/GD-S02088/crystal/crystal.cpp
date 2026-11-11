#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll w,a[N],n,m;
bool check(int x){
	ll sum=0;
	for(int i=x;i<=n;i++){
		if(i==x) {
			for(int j=1;j<x;j++){
				sum+=a[i]-a[j];
			}
		}else {
			sum=sum-a[i-1]+a[i-x];
			sum=sum+(x-1)*(a[i]-a[i-1])+a[i]-a[i-x+1];
		}
		if(sum<=m) return 1;
	}
	return 0;
}
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) w=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<w<<"\n";
	return 0;
} 
