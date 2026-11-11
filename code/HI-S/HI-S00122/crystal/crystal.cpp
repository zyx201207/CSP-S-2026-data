#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int a[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1, a+n+1);
	
	int d0;
	bool f=0;
	for(int i=2; i<=n; i++){
		int d = a[i]-a[i-1];
		if(i>=3 && d0!=d)f=1;
		d0=d;
	}
	
	if(f==0){
		if(d0==1){
			double dt = 1 + 8*m;
			double kf = sqrt(dt);
			int n = (-1 + kf) * 1.0 / 2;
			cout<<n+1;
		}else{
			double dt = 1 + (8.0/d0)*m;
			double kf = sqrt(dt);
			int n = (-1 + kf) * 1.0/(2.0/d0);
			cout<<n/d0+1;
		}
		
		return 0;
	}
	
	int ans=1;
	for(int i=2; i<=n; i++){
		int cnt=1, m1=m;
		for(int j=i-1; j>=1; j--){
			int c = a[i] - a[j];
			if(m1>=c){
				m1-=c;
				cnt++;
			}else break;
		}
		ans=max(ans, cnt);
	}
	
	cout<<ans;
	
	return 0;
}
