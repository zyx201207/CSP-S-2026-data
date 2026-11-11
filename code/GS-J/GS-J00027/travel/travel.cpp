#include<bits/stdc++.h>
using namespace std;
int c1 = 0;
int s1 = 0;
int c2 = 0;
int s2 = 0;
int main () {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2){
        cout<<"1"<<' ';
    }
    else{
        cout<<"0"<<' ';
    }
    if(s1 == s2){
        cout<<"1"<<' ';
    }
    else{
        cout<<"0"<<' ';
    }
    cout<<"0"<<' '<<"1";
return 0;
}
