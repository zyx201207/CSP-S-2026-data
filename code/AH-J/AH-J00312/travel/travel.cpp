#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool check1(char t1,char t2){
    if(t1=='A'||t1=='B'||t1=='C'){
        if(t2=='A'||t2=='B'||t2=='C')   return 1;
        return 0;
    }
    if(t1=='D'||t1=='F'){
        if(t2=='D'||t2=='F')   return 1;
        return 0;
    }
}
bool check2(char t1,char t2){
    if(t1=='A'){
        if(t2=='B')    return 1;
        return 0;
    }
    if(t1=='B'){
        if(t2=='A'||t2=='C')    return 1;
        return 0;
    }
    if(t1=='C'){
        if(t2=='B')    return 1;
        return 0;
    }
    if(t1=='D'){
        if(t2=='F')    return 1;
        return 0;
    }
    if(t1=='F'){
        if(t2=='D')    return 1;
        return 0;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)  cout<<1;
    else cout<<0;
    string a=s1.substr(0,2),b=s2.substr(0,2);
    if(c1==c2&&a==b)    cout<<1;
    else cout<<0;
    if(c1==c2&&a==b&&check1(s1[2],s2[2]))  cout<<1;
    else cout<<0;
    if(c1==c2&&a==b&&check1(s1[2],s2[2])&&check2(s1[2],s2[2]))  cout<<1;
    else cout<<0;
    return 0;
}
