#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
ll a[N],n,m,cnt,ans,res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cnt=ans=1;
	for(int i=2;i<=n;i++){
		res+=(a[i]-a[i-1])*cnt;
		cnt++;
		while(res>m){
			cnt--;
			res-=(a[i]-a[i-cnt]);
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}