#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    string s3,s4;
    char c3,c4;
    for(int i=0;i<s1.size();i++){
        if(s1[i]=='A'||s1[i]=='B'||s1[i]=='C'||s1[i]=='D'||s1[i]=='F'){
            c3=s1[i];
        }else{
            s3+=s1[i];
        }
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]=='A'||s2[i]=='B'||s2[i]=='C'||s2[i]=='D'||s2[i]=='F'){
            c4=s2[i];
        }else{
            s4+=s2[i];
        }
    }

    if(s3==s4){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(c3>='A'&&c3<='C'&&c4>='A'&&c4<='C'&&c3!=c4){
        cout<<1;
    }else if(c3=='D'&&c4=='F'||c3=='F'&&c4=='D'){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(c3=='A'&&c4=='B'||c3=='B'&&c4=='A'){
        cout<<1;
    }else if(c3=='B'&&c4=='C'||c3=='C'&&c4=='B'){
        cout<<1;
    }else if(c3=='F'&&c4=='D'||c3=='D'&&c4=='F'){
        cout<<1;
    } else{
        cout<<"0";
    }
    return 0;
}
