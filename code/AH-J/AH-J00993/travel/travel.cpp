#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1;
    string s1;
    int c2;
    string s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    string s3,s4;
    for(int i=0;i<=1;i++){
        s3+=s1[i];
    }
    for(int i=0;i<=1;i++){
        s4+=s2[i];
    }
    if(s3==s4){
        cout<<"1";
    }else{
    	cout<<"000";
    	return 0;
    }
    if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
    	cout<<"00";
    	return 0;
	}else if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'){
		cout<<"11";
	}else if(s1[2]+1==s2[2]){
		cout<<"11";
		return 0;
	}else{
		cout<<"10";
	}
    return 0;
}
