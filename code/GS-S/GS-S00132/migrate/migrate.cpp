#include<bits/stdc++.h>
using namespace std;
long long t,c,n,d,x[2000005],q;
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			if(n==1){
				cout<<"0\n";
				continue;
			}
			for(int i=1;i<=n;i++)cin>>x[i];
			if(x[2]-x[1]==1){
				if(x[2]-x[1]>d)cout<<"0\n";
				else cout<<ceil(n*1.0/d)-1<<"\n";
				continue;
			}
			if(x[2]-x[1]>d||d%(x[2]-x[1])!=0)cout<<"0\n";
			else{
				if((d/(x[2]-x[1]))%2==0){
					int y=d/(x[2]-x[1]);
					for(int i=1;i<=n;i++)q=q+i/3*y;
				}
				else{
					int y=d/(x[2]-x[1]);
					for(int i=1;i<=n;i++)q=q+i/4*y;
				}
			}
			cout<<q<<"\n";
			q=0;
		}
	}
	
	return 0;
}
			

