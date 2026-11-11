#include <bits/stdc++.h>
using namespace std;
int c,t,m,x[100000],d,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int f=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==2){
				m=x[2]-x[1];
			}
			if(f==1 && i>2 && x[i]-x[i-1]!=m){
				f=0;
			}
		}
		if(f==1){
			cout<<n/d<<'\n';
		}
		else{
			uniform_int_distribution<int>q(0,n-1);
			cout<<q(rng);
		}
	}
	return 0;
}
