#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		int x[n+5];
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		int cnt=0;
		for(int i=1;i<=n-3;i++){
			cnt+=i;
		}
		cout<<cnt;
	}
	return 0;
} 
