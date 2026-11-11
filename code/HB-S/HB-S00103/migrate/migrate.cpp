#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000009];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		long long mincha=LONG_LONG_MAX,maxcha=LONG_LONG_MIN;
		cin >> n >> d;
		for(int j=1;j<=n;j++){
			cin >> x[j];
			if(j>1){
				long long t=x[j]-x[j-1];
				//cout <<x[j] <<'-'<<x[j-1]<<'='<<t <<'\n';
				mincha=min(mincha,t);
				maxcha=max(maxcha,t);
			}
		}
		//cout << maxcha << ' ' <<mincha <<'\n';
		if(mincha==maxcha){
			if(mincha>d){
				cout<<0 <<'\n';
				continue;
			}
			if((d/2+(d%2))<mincha && mincha<=d){
				cout<<0 <<'\n';
				continue;
			}
			if(d==mincha*(n-1)){
				cout<<0 <<'\n';
				continue;
			}
			if(d==mincha){
				cout<<0 <<'\n';
				continue;
			}
			cout << 2 << '\n';
		}
	}
	return 0;
}
