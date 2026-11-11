#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],sum[N],ans,b[N];
bool check(int l,int r){
	int res=sum[r]-sum[l]-(l-1)*(b[r]-b[l]);
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
		b[i]=b[i-1]+a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
