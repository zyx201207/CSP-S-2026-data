#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005];
char c[200005];
int sum[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int mid=sum[n]/2;
	int i=1;
	for(;i<=n;i++){
		if(sum[i]>=mid){
			break;
		}
	}
	int ans=0;
	for(int j=1;j<=i;j++){
		int l1=sum[j-1]+1,r1=sum[j];
		if(j==i){
			r1=mid;
		}
		int l2=sum[n]-r1+1,r2=sum[n]-l1+1;
		int p1=lower_bound(sum+1,sum+n+1,l2)-sum;
		int p2=lower_bound(sum+1,sum+n+1,r2)-sum;
		if(p1==p2){
			ans+=(c[j]!=c[p1])*(r2-l2+1);
		}else{
			ans+=(c[j]!=c[p1])*(sum[p1]-l2+1);
			ans+=(c[j]!=c[p2])*(r2-sum[p2-1]);
			for(int k=p1+1;k<=p2-1;k++){
				ans+=(c[j]!=c[k])*a[k];
			}
		}
	}
	cout<<ans;
	return 0;
}
