#include<iostream>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	string a1=" ",a2=" ";
	a1+=c2[0]+c2[1];
	a2+=c4[0]+c4[1];
	char a3=c2[2],a4=c4[2];
	if(c1==c3){
		cout<<"1";
		if(a1==a2){
			
		    cout<<"1";
		    if(a3=='D' || a3=='F' && a4=='D' || a4=='F'){
			    cout<<"11";
			    return 0;
		    }else if(a3=='A' || a3=='B' || a3=='C' && a4=='A' || a4=='B' || a4=='C'){
		    	cout<<"1";
		    	if((int)a3-(int)a4==1 || (int)a3-(int)a4==-1){
		    		cout<<"1";
				}else{
					cout<<"0";
					return 0;
				}
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
