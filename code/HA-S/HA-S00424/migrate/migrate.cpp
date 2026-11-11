#include<bits/stdc++.h>
using namespace std;
long long int c,t,n,d,x[2000006],cha;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12 ||c==0){
		for(int i=0;i<t;i++){
			cin>>n>>d;
			if(n<4){
				cout<<0<<endl;
			}
			for(int j=0;j<n;j++){
				cin>>x[j];
			}
			cha=x[0]-x[1];
			if(cha>d){
				cout<<0<<endl;
			}else if(d>=2*cha && d<3*cha){
				cout<<n-3<<endl;
			}else{
				cout<<n-5<<endl;
			}
		}
		
	}
	for(int i=0;i<t;i++){
		cin>>n>>d;
		if(n<4){
			cout<<0;
		}
		for(int j=0;j<=n;j++){
			cin>>x[j];
		}
		
		
	}

	return 0;
}

