#include <bits/stdc++.h>
using namespace std;
int main(){
	int L;
	cin>>L;
    string S[3][100000];
    for(int i=0;i<2;i++){
    	for(int o=0;o<=L;o++){
    	cin>>S[i][o];
    	if(S[0][1]==S[0][o]){
    		cout<<0;
    		return 0;
    	}
		}
    }
    for(int i=0;i<=1;i++){
    	for(int o=0;o<=L;o++){
    		if(L%2!=0){
    			if(S[0][0]==S[0][o]){
    		cout<<(L/2);
    			}else{
    				cout<<(L/2); 
    			}
    		}else{
    		if(S[0][0]==S[0][o]){
    		cout<<(L/2-1);
		}else{
    		cout<<(L/2-1); 
    			}	
    		}
    	}
    }
return 0;
}	
