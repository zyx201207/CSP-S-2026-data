#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool che=true,pai=true,bian=true;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){cout<<"1";}
    else{
        cout<<"0";
        che=false;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&che){cout<<"1";}
    else{
        cout<<"0";
        pai=false;
    }
    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='c'&&pai){cout<<"1";}
    else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&pai){cout<<"1";}
    else{
        cout<<"0";
        bian=false;
    }
    if(abs(s1[2]-s2[2])<2&&bian){cout<<"1";}
    else{cout<<"0";}
    return 0;
}
