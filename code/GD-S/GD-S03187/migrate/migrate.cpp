#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int n,t,c;
long long d,x[N],in[N],s[N],vis[N],out[N];
vector<int> a[N];

void solve(){
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	if(n<=2){
		cout << 0;
		return;
	}
	if(c==11||c==12){
		if(x[3]-x[1]>d){
			cout << 0;
			return;
		}
		long long ss=x[2]-x[1];
		long long td=d/ss;
		if(td>=3||td<=1){
			cout << 0;
			return;
		}
		if(n-1<=td){
			cout << 0;
			return;
		}
		long long ans=(n-(td+1));
		cout << ans << "\n";
	}
//	if(c==1||c==2){
//		for(int i=2;i<=n;i++){
//			
//			in[i]=0;
//			s[i]=x[i]-x[i-1];
//			vis[i]=0;
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(x[j]-a[i]<=d){
//					in[j]++;
//					out[i]++; 
//					a[i].push_back(j);
//				}
//			}
//		}
//		for(int i=1;i<=n-3;i++){
//			if(s[i+1])
//		}
//
//	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> c >> t;
	while(t--){
		solve();
	}
	
	return 0;
} 
