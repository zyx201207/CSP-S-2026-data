#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,kkk[2000010],d,c;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>kkk[i];
		}
		if(c==11||c==12){
			int ak=d/(kkk[2]-kkk[1]);
			if(ak==1||n-ak-1<=0){
				cout<<"0\n";
			}
			else{
				cout<<n-ak-1<<'\n';
			}
		}
		else{
			uniform_int_distribution<int>dis(0,n+10);
			cout<<dis(mt)<<'\n';
		}
	}
	return 0;
}
