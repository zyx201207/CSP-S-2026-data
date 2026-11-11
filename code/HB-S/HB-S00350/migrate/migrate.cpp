#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100053];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		int n,d,a[100054];
		cin >> d >>n;
		int maxn=INT_MIN,minn=INT_MAX;
		for(int i=1;i<=d;i++){
			cin >> a[i];
			maxn=max(maxn,a[i]);
			minn=min(minn,a[i]);
		}
		if(n>=abs(maxn-minn)){cout << 0;continue;}
		int ans=0;
		for(int i=1;i<=d-3;i++){
			for(int j=i+3;j<=d;j++){
				if(abs(a[j]-a[i])%n!=0)ans+=1;
			}
		}
		cout << ans<<endl;
	}
	
	return 0;
}
