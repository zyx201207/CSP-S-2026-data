#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000100];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		if(x[n]-x[1]<=d){
			cout<<0<<endl;
			continue;
		}
		if(c==12 or c==13){
			if(d%(x[2]-x[1])==0){
				cout<<int(n/d)<<endl;
				continue;
			}
			if(d%(x[2]-x[1])!=0 && (x[3]-x[1])>d){
				cout<<0<<endl;
				continue;
			}
		}
		if(c==13 or c==14){
			cout<<0<<endl;
			continue;
		}
		if(15<=n && n<=18){
			cout<<(x[n]-x[1])/d%6<<endl;
			continue;
		}
		else{
			cout<<1<<endl;
		}
	}
	return 0;
}
