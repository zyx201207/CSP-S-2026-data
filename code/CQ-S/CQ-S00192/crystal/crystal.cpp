#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500010];
ll sum[500010];
ll getsum(int l,int r){
	return sum[r]-sum[l-1];
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
		sum[i]=sum[i-1]+a[i];
	}
	int res=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(1LL*a[i]*(i-mid+1)-getsum(mid,i)<=m)r=mid;
			else l=mid+1;
		}
		res=max(res,i-l+1);
	}
	cout<<res<<"\n";
	return 0; 
} 
