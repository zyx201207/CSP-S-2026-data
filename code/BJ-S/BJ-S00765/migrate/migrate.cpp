#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,t,n,d,x[2000006];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
			}
		if(c==11||c==12||c==0){
			//cout<<"~~~"<<x[2]-x[1]<<" "<<d/2<<endl;
			if(x[2]-x[1]>d/2){
				cout<<0<<endl;
				continue;
				}
			int cnt=d/(x[2]-x[1]);
			cnt=cnt*2-1;
			if(n-cnt<0) cout<<0<<endl;
			else cout<<n-cnt<<endl;
			}
		}
		if(c<=3){
			
			}
	return 0;
}
