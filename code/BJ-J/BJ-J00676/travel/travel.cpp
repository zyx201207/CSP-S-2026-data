#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string q1,w1,q2,w2;
    cin>>q1>>w1>>q2>>w2;
    int e1=strlen(w1);
    int e2=strlen(w2);
    if(q1!=q2){
        cout<<"0000";
        return 0;
    }
    if(e1!=e2){
        cout<<"1000";
        return 0;
    }
    for(int i=0;i<e1-1;i++){
        if(w1[i]!=w2[i]){
            cout<<"1000";
            return 0;
        }
    }
    if((w1[e1]=='C'&&w2[e2]=='B')||(w1[e1]=='B'&&w2[e2]=='C')){
        cout<<"1100";
        return 0;
    }
    if(!((w1[e1]=='F'||w1[e1]=='D')&&(w2[e2]=='D'||w2[e2]=='F'))||((w1[e1]=='A'||w1[e1]=='B'||w1[e1]=='C')&&(w2[e2]=='A'||w2[e2]=='B'||w1[e1]=='C'))){
        cout<<"1100";
        return 0;
    }
    if((w1[e1]-w2[e2]!=1)||(w2[e2]-w1[e1]!=1)){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
