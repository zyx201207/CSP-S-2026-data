#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<c1.size();i++){
        if(c1[i]!=c2[i]){
            cout<<"0000";
            return 0;
        }
    }
    cout<<"1";//di1gejieshu
    for(int i=0;i<s1.size()-1;i++){
        if(s1[i]!=s2[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<"1";//di2gejieshu
    int k=s1.size()-1;
    if(s1[k]=='A'||s1[k]=='B'||s1[k]=='C'){
        if(s2[k]=='A'||s2[k]=='B'||s2[k]=='C')cout<<"1";
        else{
            cout<<"00";
            return 0;
        }
    }
    else{
        if(s2[k]=='D'||s2[k]=='F')cout<<"1";
        else{
            cout<<"00";
            return 0;
        }
    }
    if(s1[k]=='A'&&s2[k]=='B'||s2[k]=='A'&&s1[k]=='B')cout<<"1";
    else if(s1[k]=='B'&&s2[k]=='C'||s2[k]=='B'&&s1[k]=='C')cout<<"1";
    else if(s1[k]=='D'&&s2[k]=='F'||s2[k]=='D'&&s1[k]=='F')cout<<"1";
    else cout<<"0";
    //di4gejieshu
    return 0;
}
