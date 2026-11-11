#include<bits/stdc++.h>
using namespace std;
bool k[10000];

int main(){
	freopen("travel.in"."r",stdin);
	freopen("travel.out"."w",stdout);
	k['A']=k['B']=k['C']=1;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
	    	cout<<"1";
	    	if(k[b[2]]==k[d[2]]){
	        	cout<<"1";
	        	if(abs(b[2]-d[2])==1){
	        		cout<<"1";
				}
				else{
					cout<<"0";
				}
        	}
        	else{
        		cout<<"00";
			}
     	}
     	else{
     		cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
