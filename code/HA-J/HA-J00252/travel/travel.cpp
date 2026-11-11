#include<bits/stdc++.h>
using namespace std;
string s[10000];
string ans;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=4;i++){
    	cin>>s[i];
    }
    if(s[1]==s[3]){
    	if(s[2][0]==s[4][0]&&s[2][1]==s[4][1]){
    		if(s[2][2]<='C'&&s[2][2]>='A'&&s[4][2]<='C'&&s[4][2]>='A'){
    			if(s[2][2]==s[4][2]+1||s[2][2]==s[4][2]-1){
    				cout<<"1111";
    				return 0;
    			}else{
    				cout<<"1110";
    				return 0;
    			}
    		}else if(s[2][2]=='D'&&s[4][2]=='F'||s[4][2]=='D'&&s[2][2]=='F'){
    			cout<<"1111";
    			return 0;
    		}else{
    			cout<<"1100";
    			return 0;
    		}
    	}else{
    		cout<<"1000";
    		return 0;
    	}
    }else{
    	ans="0000";
    	cout<<ans;
    	return 0;
    }
    return 0;
} 
