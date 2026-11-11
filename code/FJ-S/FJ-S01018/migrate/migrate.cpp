#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		d=d*2-1;
		cout<<max((long long)0,(x[n]-x[1])+1-d)<<"\n";
	}
	return 0;
}
