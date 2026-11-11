#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans=0;
long long n,m;
bool ck(long long len,long long k){
	long long res=0;
	for(long long i=k;i>=k-len+1;i--){
		res+=a[k]-a[i];
	}
	if(res<=m)return 1;
	else return 0;
}
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		long long l=0,r=i;
		while(l<=r){
			long long mid=(r+l)/2;
			if(ck(mid,i)){
				ans=max(ans,mid);
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
	}
	cout<<ans;
	return 0;
}

