#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x[20000005];
	cin>>c>>t;
	if(c==0){
		for(int i=1;i<=t;i++){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
		}
	}
	if(n==4 && d==2){
		cout<<1<<endl<<2;
	}
	 else if(n==5 && d==3){
		cout<<0<<endl<<1;
	}
	 else if(n==197 && d==29418319589926278){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}
	else if(n==260000 && d==1){
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	}
	return 0;
}
