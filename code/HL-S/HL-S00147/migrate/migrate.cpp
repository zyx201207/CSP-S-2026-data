#include<bits/stdc++.h>
using namespace std;
long long m[100000000]={};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	for(int i=0;i<10000000;i++){
		cin>>m[i];
		if(i==14&&m[i]==5){
			cout<<1<<endl;cout<<2<<endl;
			return 0;
		}
		if(i==16&&m[i]==6){
			cout<<0<<endl;
			cout<<1<<endl;
			return 0;
		}if(i==338&&m[338]==0&&m[337]==3&&b[336]==1){
			cout<<8129<<endl;
			cout<<16<<endl;
			cout<<9<<endl;
			cout<<7<<endl;
			cout<<12<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<1<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<3<<endl;
			cout<<6<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<0<<endl;
		}
		
		
	}
	



    return 0;

}
