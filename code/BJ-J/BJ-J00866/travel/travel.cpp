#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    if(s1 != t1){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(s2[0] != t2[0] || s2[1] != t2[1]){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    if(s2 > t2) swap(s2,t2);
    if(s2[2] == 'A' && (t2[2] == 'B' || t2[2] == 'C')
    || s2[2] == 'B' && t2[2] == 'C' || s2[2] == 'D' &&
    t2[2] == 'F'){
        cout<<"1";
        if(s2[2] == 'A' && t2[2] == 'B' || s2[2] == 'B'
        && t2[2] == 'C' || s2[2] == 'D' && t2[2] == 'F')
            cout<<"1";
        else cout<<"0";
    }
    else cout<<"00";
}
