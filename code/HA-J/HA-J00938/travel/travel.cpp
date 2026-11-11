#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ax,ay,px,py;
	cin>>ax>>ay>>px>>py;
	if(ax==px){
		cout<<1;
	    if(ay[0]==py[0]&&ay[1]==py[1]){
	    	cout<<1;
		    if(('D'<=ay[2]<='F'&&'D'<=py[2]<='F')||('A'<=ay[2]<='C'&&'A'<=py[2]<='C')){
		    	cout<<1;
		    	if(ay[2]-1==py[2]||ay[2]+1==py[2]){
		    		cout<<1;
		    	}
		    	else{
		    		cout<<0;
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
