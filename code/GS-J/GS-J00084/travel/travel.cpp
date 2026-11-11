#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0;
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(c2[0]+c2[1]==c4[1]+c4[0]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(c2[0]+c2[1]==c4[1]+c4[0]){
	    if((c2[2]=='A'||'B'||'C'&&c4[2]=='A'||'B'||'C')||(c2[2]=='D'||'F'&&c4[2]=='D'||'F')){
	    	if(c2[2]=='C'&&c4[2]=='D'){
	    		cout<<0;
			}
		    else{
		    	cout<<1;
			}
	    }
    }
	if(c2[0]+c2[1]==c4[1]+c4[0]){
	    if((c2[2]=='A'||'B'||'C'&&c4[2]=='A'||'B'||'C')||(c2[2]=='D'||'F'&&c4[2]=='D'||'F')){
	    	if(c2[2]=='A'||'B'||'C'&&c4[2]=='A'||'B'||'C'){
	    		if(c2[2]=='C'&&c4[2]=='D'){
	    			cout<<0;
	    			return 0;
				}
				else{
					if((c2[2]+1==c4[2])||(c2[2]-1==c4[2])){
	    			    cout<<1;
	    			    return 0;
				    }
				    else{
					    cout<<0;
					    return 0;
				    }
				}
			}
		    if(c2[2]=='D'||'F'&&c4[2]=='D'||'F'){
		    	cout<<1;
		    	return 0;
			}
		}
		else{
			cout<<0;
			return 0;
		}
		
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
