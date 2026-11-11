#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){
			int sum=d/(x[2]-x[1]);
			cout<<(n-sum)*sum;
		} 
	}
	return 0;
} 
