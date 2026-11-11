#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    freopen(travel.in,'r',std.in);
    freopen(travel.out,'w',std.out);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char p[3];
    int mx=max(s1[2]-'0',s2[2]-'0');
    int mn=min(s1[2]-'0',s2[2]-'0');
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        p[0]='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            p[1]='1';
        }

        if(mx-mn==1&&mn!=19){
        p[2]='1';
        p[3]='1';
        }

        else if(mx-mn==1&&mn==19){
        p[2]='0';
        p[3]='0';
        }

        else if(mx-mn==2&&mn==17){
        p[2]='1';
        p[3]='0';
        }

    }
    for(int i=0;i<=3;i++)
    cout<<p[i];
    return 0;
}
