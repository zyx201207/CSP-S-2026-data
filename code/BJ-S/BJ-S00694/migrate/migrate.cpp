#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000010;
ll c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d<(x[3]-x[2])*2){
			cout<<0<<endl;
			continue;
		}
		ll cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				cnt++;
			}
		}
		cout<<cnt/2<<endl;
	}
	return 0;
}
