#include <bits/stdc++.h>
using namespace std;
string t1,s1,t2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t1>>s1>>t2>>s2;
    if(t1==t2) cout<<1;
    else{
        cout<<"0000";
        cout.flush();
        return 0;
    }
    if(s1.substr(0,2)==s2.substr(0,2)) cout<<1;
    else{
        cout<<"000";
        cout.flush();
        return 0;
    }
    char n1=s1[2],n2=s2[2];
    if(n1=='A'||n1=='B'||n1=='C'){
        if(n2=='A'||n2=='B'||n2=='C') cout<<1;
        else{
            cout<<"00";
            cout.flush();
            return 0;
        }
    }
    if(n1=='D'||n1=='F'){
        if(n2=='D'||n2=='F') cout<<1;
        else{
            cout<<"00";
            cout.flush();
            return 0;
        }
    }
    if((n1=='A'&&n2=='B')||(n1=='B'&&n2=='A')||(n1=='B'&&n2=='C')||(n1=='C'&&n2=='B')||(n1=='D'&&n2=='F')||(n1=='F'&&n2=='D')) cout<<1;
    else cout<<0;
    cout.flush();
    return 0;  
}