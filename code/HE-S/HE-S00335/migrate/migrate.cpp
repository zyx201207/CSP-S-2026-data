#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if((x[n]-x[1])/(n-1)==x[2]-x[1]){//A
			int cha=x[2]-x[1];
			if(cha==d){
				cout<<0<<endl;
				continue;
			}
			if(d==cha+1){
				cout<<n-d-cha<<endl;
				continue;
			}
		}else{
			cout<<0<<endl;
		}
	}
	
	return 0;
}
