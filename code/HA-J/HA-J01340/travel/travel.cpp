#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,n1,n2;
	char w1,w2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<s1.size();i++){
    	if(s1[i]>='0'&&s1[i]<='9'){
    		n1+=s1[i];
    	}else{
    		w1=s1[i];
    	}
    }
    for(int i=0;i<s2.size();i++){
    	if(s2[i]>='0'&&s2[i]<='9'){
    		n2+=s2[i];
    	}else{
    		w2=s2[i];
    	}
    }
	if(c1==c2){
    	cout<<"1";
    	if(n1==n2){
    		cout<<"1";
    		if(w1>='A'&&w1<='C'&&w2>='A'&&w2<='C'||w1>='D'&&w1<='E'&&w2>='D'&&w2<='E'){
    			cout<<"1";
    			if(abs(w1-w2)==1){
    				cout<<"1";
    			}else{
    				cout<<"0"; 
    			}
    		}else{
    			cout<<"00";
    		}
    	}else{
    		cout<<"000";
    	}
    }else{
    	cout<<"0000";
    }


	return 0;
}
