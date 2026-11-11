#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans=1;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
    cout<<1;
}else{
    cout<<0;
    ans=0;
}
if(s1[0]==s2[0] and s1[1]==s2[1] and ans==1){
    cout<<1;
    if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C'){
        if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'){
            cout<<1;
            if(int(s2[2])-int(s1[2])==1 or int(s1[2])-int(s2[2])==1){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            cout<<0;
            cout<<0;
        }
    }else{
        if(s2[2]=='D' or s2[2]=='F'){
            cout<<1;
            cout<<1;
        }else{
            cout<<0;
            cout<<0;
        }
    }
}else{
    cout<<"000";
    }
return 0;
}
