#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],sum[500005],add[500005],b[500005];
bool check(int len){
	long long cost=1e18+5;
	for(int k=len+1;k<=n;k++){
		cost=min(cost,len*sum[k]-(add[k-1]-add[k-1-len]));
	}
	if(cost<=m)return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+b[i];
		add[i]=add[i-1]+sum[i];
	}
	int l=0,r=n;
	while(l+1!=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l+1;
	return 0;
} 
