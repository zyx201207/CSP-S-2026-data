#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,x[2000005];
	cin>>c>>t;
	while(t--){
		int n,d,al=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
			al+=x[i];
		}
		if(x[1]-x[0]>d){
			 cout<<0<<'\n';
			 continue;
		}
		if(x[1]-x[0]=0){
			cout<<1<<'\n';
			continue;
		}
		int cha=x[1]-x[0];
		int dd=d/cha;
		if(dd==2) cout<<n-3<<'\n';
	}
	return 0;
}
