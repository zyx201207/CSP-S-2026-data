#include<bits/stdc++.h>
using namespace std;
//long long !!!!!!!!!!!
long long n,m,a[500005],sum[500005];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("mine.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(&a[1],&a[n+1]);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int maxn=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>m) continue;
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-sum[i-1]+sum[mid-1]<=m) r=mid-1;
			else l=mid+1;
		}
		r++;
		//cout<<i<<" "<<r<<"test\n";
		maxn=max(maxn,i-r+1);
	}
	cout<<maxn;
}
