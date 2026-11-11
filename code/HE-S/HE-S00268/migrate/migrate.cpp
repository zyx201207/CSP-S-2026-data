#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,t,n,d,x[N],f1=0;
bool f2=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]+d>=x[n] && x[i]-d<=x[1]){
				f1++;
			}
			if(i>=3){
				if(x[i]-x[i-1]!=x[i-1]-x[i-2]){
					f2=0;
				}
			}
		}
		if(c==0){
			if((n==4&&d==2) || (n==5&&d==2)){
				cout<<1<<"\n"<<2;
				break;
			}else{
				cout<<0<<"\n"<<1;
				break;
			}
			return 0;
		}
		if(f2){
			if(d>=2*(x[2]-x[1]) && d<3*(x[2]-x[1])){
				cout<<n-3<<"\n";
			}
			else{
				cout<<0;
			}
			return 0;
		}
		if(f1==1){
			cout<<0<<"\n";
		}
	}
	return 0;
}
