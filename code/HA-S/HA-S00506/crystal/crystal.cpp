#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],str[500005],ans;
unsigned long long m;
bool check(long long i,long long mid){
	long long x=i-mid+1;
	long long y=mid*a[i]-(str[i]-str[x-1]);
	if(y<=m)return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		str[i]=str[i-1]+a[i];
	} 
	for(long long i=1;i<=n;i++){
		long long l=1,r=i,cnt=1;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check(i,mid)){
				l=mid+1;
				cnt=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(cnt,ans);
	}cout<<ans;
	return 0;
}
