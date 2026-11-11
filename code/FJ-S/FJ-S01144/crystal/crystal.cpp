#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],sum[N],m;
bool check(int x,int id){
	return (id-x+1)*a[id]-sum[id]+sum[x-1]<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,Ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid-1;
				ans=mid;
			}
			else{
				l=mid+1;
			}
		}
		Ans=max(Ans,i-ans+1);
	}
	cout<<Ans<<'\n';
	return 0;
}
