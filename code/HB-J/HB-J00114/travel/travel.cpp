#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    string p1=s1.substr(0,2);
    string p2=s2.substr(0,2);
    char t1=s1[2];
    char t2=s2[2];
    if(c1!=c2){
        cout<<"0000";
    }
    else if(p1!=p2){
        cout<<"1000";
    }
    else if((t1=='A'||t1=='B'||t1=='C')&&(t2=='D'||t2=='F')){
        cout<<"1100";
    }
    else if(t1=='D'||t2=='F'){
        cout<<"1111";
    }
    else{
        if(abs(t1-t2)==1){
            cout<<"1111";
        }
        else{
            cout<<"1110";
        }
    }
    return 0;
}
