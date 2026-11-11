#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n,d;
ll x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i = 1;i <= n;i++)
			cin>>x[i];
		cout<<0<<'\n';
	} 
	return 0;
}

