#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cz;
vector<int>x; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		x.resize(n);
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(n==1){
			cout<<0<<'\n';
		}else{
			cz=x[1]-x[0];
			cout<<d/cz<<'\n';
		}
	}
	return 0;
}

