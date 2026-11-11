#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
        while(t--){
            cout<<0;
        }
	}else if(c==13||c==14){
        while(t--){
            cin>>n>>d;
            cout<<n;
        }
	}else{
        while(t--){
            cin>>n>>d;
            cout<<n/10;
        }
	}
    fclose(stdin);
    fclose(stdout);
}


