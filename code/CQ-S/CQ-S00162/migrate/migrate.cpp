#include<bits/stdc++.h>
using namespace std;

int c,t;
const int N=2*1e6+5;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		long long mn=1e18+10;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			long long x;
			cin>>x;
			mn=(mn>x?x:mn);
		}
		if(mn>=d) cout<<0;
		else{
			srand(time(0));
			cout<<rand()%(n+1);
		}
	}
	return 0;
}
