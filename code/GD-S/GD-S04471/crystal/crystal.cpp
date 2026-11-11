#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500099],sum[500099],num[500099],mx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	sum[1]=0;
	num[0]=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
		if(i>=2){sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);}
		num[i]=num[i-1]+a[i];
	}
	for(long long l=1;l<n;l++){
		for(long long r=l+1;r<=n;r++){
			long long k=sum[r]-a[r]*(l-1)+num[l-1];
			if(k<=m)
			mx=max(mx,r-l+1);
		}
	}
	cout<<mx;
	return 0;
}
