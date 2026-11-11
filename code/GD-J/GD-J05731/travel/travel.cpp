#include<bits/stdc++.h>
using namespace std;
int main(){
    string c1,c2,s1,s2;
    string j="",k="";
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        cout<<'1';
        for(int i=0;i<=1;i++){
        j=j+c2[i];
        k=k+s2[i];
    }
    if(j==k){
        cout<<'1';
        if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
            cout<<'1';
            if(c2[2]=='B'||s2[2]=='B'){
                cout<<'1';
            }
            else{cout<<'0';}
        }
        
    }
    else{
        if(c2[2]=='D'||c2[2]=='F'){
            if(s2[2]=='D'||s2[2]=='F'){
                cout<<'1';
                cout<<'1';
            }
            else{cout<<'0'<<'0';}
            
        }
        
    }
    }else{cout<<'0'<<'0';}
    
    }
    else{cout<<'0'<<'0'<<'0'<<'0';}
    
    return 0;
}