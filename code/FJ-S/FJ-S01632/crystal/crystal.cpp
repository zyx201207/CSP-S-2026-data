#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,c,ans;
long long a[N],sum[N],sum2[N];
bool flag=1,flag2=1;
bool check(long long x){
	long long v=c*x*(x-1)/2;
	if(v<=m)return 1;
	else return 0;
}
bool check2(long long x){
	long long v=(x-1)*sum[x]-sum2[x-1];
	if(v<=m)return 1;
	else return 0;
}
bool check3(int i,long long x){
	long long v=(x-1)*sum[i+x]-sum2[i+x-1]+sum2[i-1];
	if(v<=m)return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i]-a[i-1];
		sum2[i]=sum2[i-1]+sum[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>2)
			flag=0;
		if(a[i]<a[i-1]&&i>1)
			flag2=0;
	}
	if(flag&&flag2){
		c=a[2]-a[1];
		long long l=1,r=n;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(check2(mid))l=mid+1;
			else r=mid-1;
		}
		cout<<r;
	}
	else if(flag2){
		long long l=1,r=n;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(check2(mid))l=mid+1;
			else r=mid-1;
		}
		cout<<r;
	}
	else{
		long long l=1,r=n;
		while(l<=r){
			long long mid=(l+r)>>1;
			bool flag3=1;
			for(int i=1;i<=n;i++){
				if(i+mid>n)break;
				if(check3(i-1,mid)){
					l=mid+1;
					flag3=0;
					break;
				}
			}
			if(flag3)r=mid-1;
		}
		cout<<r;
	}
	return 0;
}
