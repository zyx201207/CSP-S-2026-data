#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]!=c2[0]||c1[1]!=c2[1]){
        cout<<0<<0<<0<<0;
    }
    else{
        int h1=(s1[0]-'0')*10+(s1[1]-'0');
        int h2=(s2[0]-'0')*10+(s2[1]-'0');
        if(h1!=h2){
            cout<<1000;
        }
        else{
            if(s1[2]=='D'&&s2[2]=='E')cout<<1111;
            else if(s1[2]=='A'&&s2[2]=='B')cout<<1111;
            else if(s1[2]=='A'&&s2[2]=='C')cout<<1110;
            else if(s1[2]=='B'&&s2[2]=='C')cout<<1111;
            else if(s2[2]=='D'&&s1[2]=='E')cout<<1111;
            else if(s2[2]=='A'&&s1[2]=='B')cout<<1111;
            else if(s2[2]=='A'&&s1[2]=='C')cout<<1110;
            else if(s2[2]=='B'&&s1[2]=='C')cout<<1111;
            else cout<<1100;
        }
    }
    return 0;
}
