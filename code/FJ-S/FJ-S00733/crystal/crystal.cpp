#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
int a[500005];
bool fa=1;
long long ans=0;
long long s[500005];
bool check(long long x){
	long long sum=LONG_LONG_MAX,cnt=0;
	for(int i=x;i<=n;i++){
		sum=min(a[i]*x-(s[i]-s[i-x]),sum);
//		sum+=a[x]-a[i];
//		if(sum>m)return 0;
//		cnt++;
//		ans=max(ans,cnt);
	}
	return sum<=m;
}
long long binary_search(long long l,long long r){
	while(l<=r){
		long long mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long x=binary_search(0,n);
	cout<<x<<'\n';
	return 0;
}

