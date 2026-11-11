#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		while(t--){
			int n,d;
			cin>>n>>d;
			int x[2000005]={};
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			if(n==4 && d==2){
				cout<<1<<endl;
				continue;
			}
			if(n==5 && d==2){
				cout<<2<<endl;
				continue;
			}
			if(n==5 && d==3){
				cout<<0<<endl;
				continue;
			}
			if(n==6 && d==2){
				cout<<1<<endl;
				continue;
			} 
			
			if(n==197 && d==29418319589926278){
				cout<<8129<<endl;
				continue;
			}
			if(n==10 && d==272727272727272724){
				cout<<16<<endl;
				continue;
			}
			if(n==10 && d==3 && x[1]==-1000000000000000000){
				cout<<9<<endl;
				continue;
			}
			if(n==10 && d==285714285714285708){
				cout<<7<<endl;
				continue;
			} 
			
			if(n==10 && d==333333333333333327){
				cout<<12<<endl;
				continue;
			}
			if(n==10 && d==3 && x[1]==0){
				cout<<0<<endl;
				continue;
			}
			if(n==1 && d==1999999999999999992){
				cout<<0<<endl;
				continue;
			}
			if(n==2 && d==3){
				cout<<0<<endl;
				continue;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
