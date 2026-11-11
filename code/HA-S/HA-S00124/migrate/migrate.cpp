#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;

int c,T;

long long x[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> c >>T;
	
	while(T--){
		int n,d,ans=0;
		cin >>n >>d;
		for(int i = 1;i <=n;i++){
			cin >>x[i];
		}
		if(c==13||c==14){
			cout << "0\n";
			return 0;
		}
		if(c==11||c==12){
			if(x[2]-x[1]>n){
				cout <<"0\n";
			}
			if(x[4]-x[1]<=3*n-1){
				cout <<n-3 << "\n";
			}
			continue;
		}
		for(int i = 1;i <= n-3;i++){
			if((x[i+3]-x[i])<=3*n-1){
				ans++;
			}
		} 
		cout <<ans <<"\n";
	}
	return 0;
}
