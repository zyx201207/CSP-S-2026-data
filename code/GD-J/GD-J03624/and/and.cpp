#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long mxm=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxm=max(mxm,a[i]);
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	long long mx=0;
	if(m==1){
		cout<<mxm;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int y=i+1;y<=n;y++){
				mx=max(mx,a[i]^a[y]);
			}
		}
		cout<<mx;
	}else if(n==m){
		cout<<sum[n];
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			mx=max(mx,sum[i]|=a[i]);
		}
		cout<<mx;
	}else{
		for(int i=1;i<=m-1;i++){
			mx=max(mx, sum[n]|sum[n-i-m]^sum[i]);
		}
		for(int i=m;i<=n;i++){
			mx=max(mx,sum[i]|sum[i-m]);
		}
		cout<<mx;
	}
	return 0;
}
