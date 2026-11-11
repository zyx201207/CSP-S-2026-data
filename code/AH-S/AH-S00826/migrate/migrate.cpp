#include<bits/stdc++.h>
using namespace std;
long long a[200005],d;
int n;
bool panduan(long long b,long long c){
    if (__gcd(c,b)==1) return true;
	else return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			if (a[i]-a[i-1]>d) a[i]=-9999999999999999;
		}
		int ans=0;
		for (long long i=1;i<n;i++){
			if (a[i]==-9999999999999999) continue;
			for (long long j=i+3;j<=n;j++){
				if (panduan(a[j]-a[i],d)&&j-i>=3&&a[j]!=-9999999999999999){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
