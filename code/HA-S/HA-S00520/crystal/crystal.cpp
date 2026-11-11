#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],sum,maxx;
void erfen(long long i){
	long long l=0,r=i,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		long long x=a[i]*(i-mid)-(b[i-1]-b[mid-1]);
		if(x==m){
			break;
		}
		if(x<m){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	sum=i-mid+1;
	maxx=max(maxx,sum);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		erfen(i);
	}
	cout<<maxx;
	return 0;
}
