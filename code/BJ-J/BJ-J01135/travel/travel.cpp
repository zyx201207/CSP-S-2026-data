#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;

string c1,c2,s1,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;                //in
    if(c1==c2){                         //same part
        cout<<1;

        bool ff=1;
        for(int i=0;i<=1;i++)
            if(s1[i]!=s2[i]) ff=0;
        if(ff==1){
            cout<<1;                    //same line

            if(s1[2]=='A')              //A
                if(s2[2]=='B') cout<<11<<"\n";
                else if(s2[2]=='C') cout<<10<<"\n";
                else cout<<0<<0<<"\n";
            else if(s1[2]=='B')         //B
                if(s2[2]=='A'||s2[2]=='C') cout<<11<<"\n";
                else cout<<0<<0<<"\n";
            else if(s1[2]=='C')         //C
                if(s2[2]=='B') cout<<11<<"\n";
                else if(s2[2]=='A') cout<<10<<"\n";
                else cout<<0<<0<<"\n";
            else if(s1[2]=='D' && s2[2]=='F') cout<<11<<"\n";
            else if(s2[2]=='D' && s1[2]=='F') cout<<11<<"\n";
            else {
                cout<<0<<0<<"\n";
            }
        }
        else cout<<0<<0<<0<<"\n";           //diff line=>1000

    }
    else cout<<0<<0<<0<<0<<"\n";              //diff part=>0000
    return 0;
}
