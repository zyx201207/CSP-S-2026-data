#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N],ans=-0x3f3f3f3f;
long long pre[N];
bool check(int k,int r){
	long long sum=(r-k)*a[r];
	sum-=(pre[r-1]-pre[k-1]);
	if(sum<=m){
		return 1;
	}else{
		return 0;
	}
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
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		long long id=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				id=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-id+1);
	}
	cout<<ans;
	return 0;
}
