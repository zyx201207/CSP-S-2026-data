#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],b[500050],c[500050],ans=1,sum;
long long d[500050],mi;
vector<long long>v;
bool check(long long mid){
	mid--;
	sum=0;mi=LONG_LONG_MAX;
	for(long long i=1;i<=mid;i++)sum+=b[i]*i;
	mi=sum;
	for(long long i=1,j=mid;j<n-1;i++,j++){
		sum=sum-(c[j]-c[i-1])+mid*b[j+1];
		mi=min(sum,mi);
	}
	if(mi<=m)return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		b[i]=a[i+1]-a[i];
		c[i]=b[i]+c[i-1];
	}
	long long l=1,r=n,mid=(l+r)/2;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
			ans=l;
		}else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}

