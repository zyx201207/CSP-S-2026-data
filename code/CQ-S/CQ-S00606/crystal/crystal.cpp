/*
нрл╚╡как

100+100+[28,48]+15

*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+12;

int n;ll m;
ll a[N];
ll sum[N];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	int Ans=1;
	for(int i=1;i<=n;++i){
		int L=1,R=i,ans=1;
		while(L<=R){
			int mid=(L+R)>>1;
//			cerr<<L<<" "<<R<<" "<<"mid:"<<mid<<" "<<a[i]<<" "<<i-mid+1<<" "<<sum[i]-sum[mid-1]<<endl; 
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				ans=i-mid+1;
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		Ans=max(Ans,ans);
//		cerr<<i<<" "<<ans<<endl;
//		cerr<<"---\n";
	}
	cout<<Ans;
	
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
