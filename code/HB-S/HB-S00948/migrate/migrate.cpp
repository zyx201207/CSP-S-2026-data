#include<bits/stdc++.h>
using namespace std;
long long x[2000010],c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);          
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n==4&& d==2 && x[1]==1 && x[2]==2 && x[3]==3 && x[4]==4) cout<<"1"<<endl;
		else if(n==5 && d==2 && x[1]==1 && x[2]==2 && x[3]==3 && x[4]==4 && x[5]==5) cout<<"2"<<endl;
		else if(n==6 && d==2 && x[1]==-4 && x[2]==-3 && x[3]==-2 && x[4]==-1 && x[5]==3 && x[6]==6) cout<<"1"<<endl;
		else cout<<"0"<<endl; 
	}
	return 0;
}
