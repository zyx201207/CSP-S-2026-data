#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout)
	cin >> n >> m;
	int cnt=0,ma=0,mn;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) cnt++;
		else cnt=1;
		if(cnt>ma) ma=cnt,mn=a[i];
	}
	int k=upper_bound(a+1,a+n+1,mn)-a;
	for(int i=k-1;i>=1 && m>=1;i--){
		m-=mn-a[i],ans++;
	}
	if(m>0){
		while(1){
			m-=(a[k]-a[k-1])*k;
			if(m<=0) break;
			else ans++,k++;
		}
	}
	cout << ans;
	return 0;
}