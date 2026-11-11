#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],qian[500005];
long long f(long long k){
	if(k<0)return -k;else return k;
}
bool pan(long long w){
	for(long long i=w;i<=n;++i){
		//cout<<f(a[i]*w-(qian[i]-qian[i-w]))<<i<<' '<<w<<endl;
		if(f(a[i]*w-(qian[i]-qian[i-w]))<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
	    cin>>a[i];
	    //cout<<a[i]<<endl;
	    //qian[i]=qian[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
	    qian[i]=qian[i-1]+a[i];
	}
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(pan(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
} 
