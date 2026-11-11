#include<bits/stdc++.h>

using namespace std;

string s1a,s1b,s2a,s2b;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1a>>s1b>>s2a>>s2b;
    if(s1a!=s2a){
        cout<<"0000"<<endl;
        return 0;
    }
    if(s1b[0]!=s2b[0] || s1b[1]!=s2b[1]){
        cout<<"1000"<<endl;
        return 0;
    }
    if(s1b>s2b){
        swap(s1b,s2b);
    }
    int l1=s1b[2]-'A'+1,l2=s2b[2]-'A'+1;
    if(l1>l2){
        swap(l1,l2);
    }
    if(l1<=3 && l2>=4){
        cout<<"1100"<<endl;
        return 0;
    }
    if(l2-l1!=1){
        cout<<"1110"<<endl;
        return 0;
    }
    cout<<"1111"<<endl;
    return 0;
}

