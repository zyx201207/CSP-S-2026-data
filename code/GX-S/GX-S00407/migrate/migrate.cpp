#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000006],p[2000006],dp[10005][10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		for(long long j=1;j<=n;j++){
			cin>>a[j];
			p[j]=a[j]-a[j-1];
		}
		int zd=d/p[2];
		zd=n/zd;
		cout<<zd<<endl;
	}
    return 0;
}

