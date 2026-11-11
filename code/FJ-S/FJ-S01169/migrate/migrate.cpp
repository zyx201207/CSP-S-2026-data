#include<bits/stdc++.h>
using namespace std;
long long n,m,c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		vector<long long>v(n+2);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		if(m==2){
			if(n<4){
				cout<<0<<'\n';
			}if(n>=4){
				cout<<1+(n-4)<<'\n';
			}
		}
	}
	return 0;
}

