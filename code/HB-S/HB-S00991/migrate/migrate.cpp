#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int c,t,x[maxn],n,d;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++)cin>>x[j];
		cout<<n-d<<'\n';
	}
	return 0;
}
