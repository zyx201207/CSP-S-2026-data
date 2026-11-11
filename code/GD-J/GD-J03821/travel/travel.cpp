#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string p1,p2,c1,c2;
	int sum=0,d=0;
	cin>>p1>>c1>>p2>>c2;
	//1
	if(p1==p2){
		cout<<"1";
		sum++;
	}else{
		cout<<"0";
	}
	//2
	if(sum==1){
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
    		cout<<"1";
    		sum++;
        }else{
        	cout<<"0";
		}
	}else{
		cout<<"0";
	}
	//3
	if(sum==2){
		if(c1[2]=='D'||c1[2]=='F'){
		    if(c2[2]=='D'||c2[2]=='F'){
		    	cout<<"1";
		    	sum++;
		    	d++;
	    	}else{
		    	cout<<"0";
	    	}
    	}else if(c1[2]=='A'||c1[2]=='B'||c1[2]=='C'){
	    	if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
		    	cout<<"1";
		    	sum++;
	    	}else{
		    	cout<<"0";
	    	}
	    }else{
	    	cout<<"0";
	    }
	}else{
		cout<<"0";
	}
	//4
	if(sum==3){
		if(c1[2]=='A'&&c2[2]=='B'){
    		cout<<"1";
        }else if(c1[2]=='C'&&c2[2]=='B'){
    		cout<<"1";
        }else if(d==1){
		    cout<<"1";
		}else if(c1[2]=='B'&&c2[2]=='A'){
			cout<<"1";
		}else if(c1[2]=='B'&&c2[2]=='C'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	
	
	return 0;
} 
