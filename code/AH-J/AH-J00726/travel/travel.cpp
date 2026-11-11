#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        string a=s1.substr(0,2),b=s2.substr(0,2);
        if(a==b){
            cout<<1;
            char c=s1[2],d=s2[2];
            if(c=='D' && d=='F' || c=='F' && d=='D' || c=='A' && d=='B' || c=='B' && d=='A' || c=='B' && d=='C' || c=='C' && d=='B') cout<<"11";
            else if(c=='A' && d=='C' || c=='C' && d=='A') cout<<"10";
            else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
