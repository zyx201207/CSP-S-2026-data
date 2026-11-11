#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    cin >> c1 >> c2;
    string s1[2]={};
    string s2[2]={};
    for(int i=0;i<3;i++)
        cin >>s1[i];
    for(int i=0;i<3;i++)
        cin >>s2[i];
    if(c1==c2) cout << 1;
    else cout << 0;
    if(s1[0]==s2[0] && s1[1]==s2[1]) cout << 1;
    else cout << 0;
    string n[2]={"A","B","C"};
    string n2[1]={"D","F"};
    for(int i=0;i<3;i++){
        if(s1[2]==n[i] && s2[2]==n[i])
            cout << 1;
        if(s1[2]==n2[i] && s2[2]==n2[i]);
            cout << 1;
        else cout << 0;
    }
    for(int i=0;i<3;i++){
        if(s1==n[i] && s2==n[i+1] || s2==n[i] && s1==n[i+1]) cout << 1;
        else cout << 0;
        if(s1==n2[i] && s2==n2[i+1] || s2==n2[i] && s1==n2[i+1]) cout << 1;
        else cout << 0;
    }

    return 0;
}
