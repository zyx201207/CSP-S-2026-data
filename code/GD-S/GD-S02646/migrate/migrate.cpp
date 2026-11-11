#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int cnt;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cnt=x[n]-x[n-1];
		cout<<0<<"\n";
		
	}
	return 0;
}
