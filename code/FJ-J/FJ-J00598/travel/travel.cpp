#include<bits/stdc++.h> 
using namespace std;
string co,so,ct,st;
const int M=1e5+20;
int a[M];
int main(){
	freopen("travel4.in","r",stdin);
	freopen("travel4.out","w",stdout);
	cin>>co>>so>>ct>>st;
	if(co[0]==ct[0]&&co[1]==ct[1]){
		cout<<1;
		if((so[0]==st[0])&&(so[1]==st[1])){
		    cout<<1;	
		    if((so[2]-'0')-(st[2]-'0')<=3){
		        if((so[2]=='C'&&st[2]=='D')||(so[2]=='D'&&st[2]=='C')){
			   	   cout<<0;  
	            }
	            else  cout<<1;
            } 
            if(((so[2]-'0')-(st[2]-'0')==1)||((st[2]-'0')-(so[2]-'0')==1)){
		        cout<<1;
	        }
	        else cout<<0;
	    }
	    else  cout<<0<<0<<0;
	
	}
	else  cout<<0<<0<<0<<0;
	
	return 0;
}
