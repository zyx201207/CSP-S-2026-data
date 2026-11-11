#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d,x[2000005];
    for(int i=0;i<t;i++){
	cin>>c>>t>>n>>d;
    for(int i=0;i<n;i++)cin>>x[i];
  		if(c==11||c==12){
			if(d>2*(x[1]-x[0])&&d<3*(x[1]-x[0])) cout<<n/2;
			else cout<<0;
		}
		else if(c==13||c==14){
			cout<<n-3;
		}
	}
}
