#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3){
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<1;
    if(s2[0]!=s4[0] || s2[1]!=s4[1]){
        cout<<"000"<<endl;
        return 0;
    }
    cout<<1;
    char c1=s2[2],c2=s4[2];
    if(c1>c2) swap(c1,c2);
    if(c1=='D' && c2=='F'){
        cout<<"11"<<endl;
        return 0;
    }else if(c1=='A' && c2=='B'){
        cout<<"11"<<endl;
        return 0;
    }else if(c1=='B' && c2=='C'){
        cout<<"11"<<endl;
        return 0;
    }else if(c1=='A' && c2=='C'){
        cout<<"10"<<endl;
    }else{
        cout<<"00"<<endl;
    }
    return 0;
}
