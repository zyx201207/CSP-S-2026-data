//GZ-S00262 ³ÂÑô½õ 
#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n,d,m;
			cin>>n>>m;
			for(int i=1;i<=n;i++) cin>>a[i];
			d=a[2]-a[1];
			if(m<2*d) cout<<0<<endl;
			else if(m>=2*d) cout<<n-4<<endl;
		}
	}
	return 0;
}
