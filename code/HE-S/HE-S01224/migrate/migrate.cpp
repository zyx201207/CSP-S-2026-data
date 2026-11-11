#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,T,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		ll ans=0;
		if(c>=11 && c<=12){
			int dc=x[2]-x[1];
			int s=d/dc;
			for(int i=1;i+max(s+1,3)<=n;i++){
				ans+=max(min(2*s-1,int(n-i))-max(s+1,3),0);
			}
		}
		cout << ans <<'\n';
	}
	return 0;
}
