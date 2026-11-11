#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const int INF=0x3f3f3f3f;
ll n,m;
ll sum[N],a[N];
bool check(int k){
	for(int i=1;i+k-1<=n;i++){
		int r=i+k-1;
		ll cost=a[r]*k-(sum[r]-sum[i-1]);
		if(cost<=m){
			return true;
		}
	}
	return false;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 

