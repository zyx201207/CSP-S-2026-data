#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=2e5+5;
int n;
ll sum[N];
ll a[N];
char c[N];
void solve(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i] >> c[i];
		sum[i]=sum[i-1]+a[i];
	}
	ll len=sum[n];
	ll ans=0;
//	//for(int i=1;i<=n;++i)cout << sum[i] << ' ';
	//cout << '\n';
	for(int i=1;i<=n;++i){
		if(sum[i-1]+1>=len/2ll+(len&1)){
			break;
		}
		ll st=sum[i-1]+1,ed=sum[i];
		if(1){
			ll s1=len+1-st,e1=len+1-ed;
			ll s2=lower_bound(sum+1,sum+n+1,s1)-sum-1+1,e2=lower_bound(sum+1,sum+n+1,e1)-sum-1+1;
			ll res=ans;
			//cout << i << " " << st << " " << ed << " " << s1 << " " << e1 << " " << s2 << " " << e2 << c[i] << " " <<  '\n'; 
			for(int j=e2;j<=s2;++j){
				
				if(c[j]==c[i])continue;
				if(sum[j]<e1&&sum[j+1]>=s1){
					ans+=s1-e1+1;
				}
				else if(sum[j-1]<e1&&sum[j]>=s1){
					ans+=s1-e1+1;
				}
				else if(sum[j]<e1&&sum[j+1]>=e1){
					ans+=sum[j+1]-e1+1;
					
				}
				
				else if(sum[j-1]<e1&&sum[j]>=e1){
					ans+=sum[j]-e1+1;
				}
				else if(sum[j-1]<s1&&sum[j]>=s1){
					ans+=s1-sum[j-1];
				}

				else{
					ans+=sum[j]-sum[j-1];
				}
				
			}
			//cout << ans-res << '\n';
		}
	}
	cout << ans;
	
	return ;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int _T=1;//cin >> _T;
	while(_T--){
		solve();
	}
	return 0;
}
