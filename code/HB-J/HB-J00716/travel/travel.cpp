#include<bits/stdc++.h>
using namespace std;
string s,s1,c,c1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s>>s1>>c>>c1;
    if(s==c)cout<<"1";
    else {
        cout<<"0000";
        return 0;
    }
    if(s1[0]==c1[0]&&s1[1]==c1[1])cout<<"1";
    else {
        cout<<"000";
        return 0;
    }
    int a=int(s1[2]),b=int(c1[2]);
    if(a==65||a==66||a==67){
        if(b==68||b==70)cout<<"0";
        else cout<<"1";
    }
    else {
        if(b==68||b==70)cout<<"1";
        else cout<<"0";
    }

    if(a+1==b||a-1==b){
        if((a==67&&a+1==b)||(a==68&&a-1==b))cout<<"0";
        else cout<<"1";
    }
    else {
        if((a==68&&a==70)||(a==70&&b==68))cout<<"1";
        else cout<<"0";
    }
    return 0;
}
