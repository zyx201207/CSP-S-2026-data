#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	int s1=(c2[0]-48)*10+(c2[1]-48),s2=(c4[0]-48)*10+(c4[1]-48);
	char f1,f2; 
	f1=c2[2];
	f2=c4[2];
	if(c1==c3){
		cout<<1;
	    if(s1==s2){
	    	cout<<1;
			if((f1<='C'&&f2<='C')||(f1>'C'&&f2>'C')){
		        cout<<1;
				if(f1-f2==1||f2-f1==1||(f2=='F'&&f1=='D'||f2=='D'&&f1=='F')){
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
		else{
			cout<<0<<0<<0;
		}
    }
    else{
    	cout<<0<<0<<0<<0;
	}
	return 0;
}
