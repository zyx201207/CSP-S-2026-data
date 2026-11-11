#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a[]={0,0,0,1,1};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(s1[2]=='F')s1[2]='E';
    if(s2[2]=='F')s2[2]='E';
    if(c1!=c2)cout<<"0000";
    else{
        if(s1.substr(0,2)!=s2.substr(0,2))cout<<"1000";
        else{
            if(a[s1[2]-'A']!=a[s2[2]-'A'])cout<<"1100";
            else{
                if((int)(s1[2])-(int)(s2[2])!=1&&(int)(s2[2])-(int)(s1[2])!=1)cout<<"1110";
                else cout<<"1111";
            }
        }
    }
    return 0;
}
