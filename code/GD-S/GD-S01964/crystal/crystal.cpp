#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int t=2,w=1,ans=1;
	while(t<=n){
		if(m-(a[t]-a[t-1])*(t-w)>=0){
			m-=(a[t]-a[t-1])*(t-w);
			ans=max(ans,t-w+1);
			t++;
		}else{
			m+=a[t-1]-a[w];
			w++;
		}
		
	}
	cout << ans;
	return 0;
}
