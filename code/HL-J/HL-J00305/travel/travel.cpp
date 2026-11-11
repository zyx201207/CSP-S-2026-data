#include<bits/stdc++.h>
using namespace std;
int main(){
    frepen("travel.in","r",stdin);
    frepen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=2;i<=17;i++){
        if(i=c1){
        	if(i=c2){
            cout<<1;
            
        	break;
        }

    }
}
int c=s1[2];
int w=s2[2];
  	if(s1[2]-s2[2]==1){
  		cout<<1;
	  }
    else cout<<0;
   
    if(s1=="A"){
    	if(s1=="B"){
    		if(s1=="C"){
    		   if(s2=="A"||s2=="B"||s2=="C"){
        		cout<<1;
        		}
			}
		}

    }
    if(s1=="D"||s1=="F"){
        if(s2=="D"||s2=="F"){
        cout<<1;
        }
    }
    else cout<<0;
    
    return 0;
}
