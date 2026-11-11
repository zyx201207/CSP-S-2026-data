#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,w[500008];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		if(n%2==1) n++;
		cout<<(n-d)/d<<"\n";
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
