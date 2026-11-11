#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,s=0,d=0;
	string z,x,c,v;
	cin>>z>>x>>c>>v;
	if(z==c){
	    cout<<"1";
	    for(int i=1;i<=10;i+=9){
			a=a*10+x[d];
			s=s*10+v[d];
			d++;
		}
		if(a==s){
			cout<<"1";
			if(x[3]>='D'&&v[2]>='D'||x[2]<='C'&&v[2]<='C'){
				cout<<"1";
				if(x[2]>='D'&&v[2]>='D'){
					cout<<'1';
				}else if(x[2]=='A'){
					if(v[2]=='B'){
						cout<<"1";
					}else{
						cout<<"0";
					}
		    	}else if(x[2]=='C'){
		    		if(v[2]=='B'){
		    			cout<<"1";
					}else{
						cout<<"0";
					}
			    }else{
			    	if(v[2]=='A'||v[2]=='C'){
			    		cout<<"1";
					}else{
						cout<<"0a";
					}
				}
			}else{
				cout<<"00";
			}
    	}else{
    		cout<<"000";
		}
    }else{
		cout<<"0000";
	}
    return 0;
}