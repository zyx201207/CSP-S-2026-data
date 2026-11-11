#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a,b,c,d;
   	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}
	if(a==c){
			if( b[1]!=d[1] ){
				cout<<"1000";
			
			}
			if(b[1]==d[1]){
				if(b[2]='D' and d[2]!='F'){
					cout<<"1100";
				}
				
		}
	}
    return 0;
}
