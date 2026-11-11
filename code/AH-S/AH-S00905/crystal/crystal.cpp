#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5+5;
ll n,m;
ll a[N];
ll cnt,mm;
ll ans;
ll dlt;
ll flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=5005){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			mm=m;cnt=1;
			for(int j=i-1;j>=1;j--){
				if(mm-a[i]+a[j]<0)break;
				cnt++;mm-=a[i]-a[j];
			}
			ans=max(ans,cnt);
		}
		cout << ans;	
		return 0;
	}
	dlt=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=dlt){
			flag=0;
			return 0;
		}
	}
	mm=m;ans=1;
	for(int i=n;i>=1;i--){
		if(mm-a[n]+a[i]<0)break;
		ans++;mm-=a[n]-a[i];
	}	
	cout << ans;
	return 0;
}
