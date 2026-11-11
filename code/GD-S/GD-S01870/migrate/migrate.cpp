#include <bits/stdc++.h>
using namespace std;
const int Max=5005;
long long c,t;
long long n,d,ans;
long long a[Max];
int main(){
	freopen("migrate.in","w",stdin);
	freopen("migrate.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		if(d==1) cout<<0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+2;j<=n;j++){
				if(a[j]=a[i]+2*d-1) ans++;
			}
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
