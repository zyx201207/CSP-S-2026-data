#include<bits/stdc++.h>
using namespace std;
string r,x;
int R,X,R1,X1;
char rs,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R>>r>>X>>x;
	rs=r[2];
	xs=x[2];
	R1=int(r[0])*10+int(r[1]);
	X1=int(x[0])*10+int(x[1]);
	if(R==X){
		cout<<"1";
		if(X1==R1){
			cout<<"1";
			if((rs=='A'||rs=='B'||rs=='C')&&(xs=='A'||xs=='B'||xs=='C')||(rs=='D'||rs=='E')&&(xs=='D'||xs=='E')){
				cout<<"1";
				if(abs(int(rs-xs))==1) cout<<"1";
				else cout<<"1";
			}else{
	    		cout<<"00";
		    	return 0;
			}
	    }else{
	    	cout<<"000";
		    return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
