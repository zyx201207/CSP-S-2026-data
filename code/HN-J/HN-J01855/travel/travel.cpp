#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xr,yr,xx,yx;
	cin>>xr>>yr>>xx>>yx;
	if(xr==xx&&(xx!=01&&xx!=16)){
	cout<<1;
	} else{
		cout<<0;
	}
	if(yr[1]==yx[1]&&yr[2]==yx[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(((yr[3]=='A'||yr[3]=='B'||yr[3]=='C')&&(yx[3]=='A'||yx[3]=='B'||yx[3]=='C'))||((yr[3]=='D'||yr[3]=='E')&&(yx[3]=='D'||yx[3]=='E'))){
		cout<<1;
		if((yr[3]=='D'||yr[3]=='E')&&(yx[3]=='D'||yx[3]=='E')){
        	cout<<1;
    	}else if(yr[3]+1==yx[3]||yr[3]-1==yx[3]){
    		cout<<1;
	    }else{
    		cout<<0;
    	}
	}else{
		cout<<0;
	}
	
	return 0;
}//Trick||Treat!
