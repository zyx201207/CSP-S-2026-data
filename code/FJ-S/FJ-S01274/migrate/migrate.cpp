#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
int c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int dis=x[2]-x[1];
			if(dis*2>d) cout<<0<<endl;
			else cout<<n-2<<endl;
		}
	}
	return 0;
}
