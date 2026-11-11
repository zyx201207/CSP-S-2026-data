#include<bits/stdc++.h>
using namespace std;
string s,c,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>c>>x>>y;
	if(s==x){
		cout<<1;
		if(c[0]==y[0]&&c[1]==y[1]){
			cout<<1;
			if(c[2]=='A'||c[2]=='B'||c[2]=='C'){
				if(y[2]=='A'||y[2]=='B'||y[2]=='C'){
					cout<<1;
					if(c[2]-1==y[2]||c[2]+1==y[2]){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<0<<0;
				}
			}
			else if(c[2]=='D'||c[2]=='E'){
				if(y[2]=='D'||y[2]=='E'){
					cout<<1<<1;
				}
				else{
					cout<<0<<0;
				}
			}
	    }
	    else{
		    cout<<0<<0<<0;
    	}
    	
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
