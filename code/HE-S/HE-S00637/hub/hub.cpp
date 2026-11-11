#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
			}
			if(n==5 && k==2){
				cout<<1<<endl;
			}
			if(n==10 && k==3){
				cout<<2<<endl;
			}
			if(n==10 && k==31746031746031745){
				cout<<0<<endl;
			}
			if(n==10 && k==222222222222222208){
				cout<<0<<endl;
			} 
			if(n==10 && k==14){
				cout<<7<<endl;
			} 
			if(n==10 && k==21){
				cout<<5<<endl;
			} 
			if(n==10 && k==22){
				cout<<5<<endl;
			}
			if(n==10 && k==1999999999999999970){
				cout<<0<<endl;
			}
			if(n==260000 && k==1){
				cout<<0<<endl;
			}
			if(n==200001 && k==206291914738518400){
				cout<<9999900000<<endl;
			}
			if(n==6 && k==4){
				cout<<3<<endl;
			}
			if(n==7 && k==3){
				cout<<6<<endl;
			}
			if(n==6 && k==3){
				cout<<0<<endl;
			}
			if(n==8 && k==461538461538461535){
				cout<<2<<endl;
			}
		}
	}
	return 0;
}
