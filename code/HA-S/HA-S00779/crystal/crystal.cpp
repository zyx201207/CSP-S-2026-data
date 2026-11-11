#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
bool cmp(int x,int y){
	return x<y;
}
bool check(int x){
	int sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[i];
	}
	for(int i=x;i<=n;i++){
		int qian=i-x;
		if(i!=x){
			sum+=a[i];
			sum-=a[qian];
		}
		int k=a[i]*x-sum;
		if(k<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<max(check(l)*l,check(r)*r);
	
	return 0;
}
