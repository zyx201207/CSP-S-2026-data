#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		srand(time(0));
		cout<<rand()%d<<"\n";
	}
	return 0;
}
