#include<bits/stdc++.h>
using namespace std;
bool f,f1,f2,f3;
string c1,s1,c2,s2;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            cout<<"0000";
            return 0;
        } else{
            f=1;
        }

        if(s1[i]!=s2[i]){
            cout<<"000";
            return 0;
        } else{
            f1=1;
        }
    }
    if(f1==1){
        cout<<"1";
    }
    if(f==1){
        cout<<"1";
    }
    if(s1[2]=='F'||s1[2]=='D'){
        if(s2[2]!='F'&&s2[2]!='D'){
            cout<<"00";
            return 0;
        }
    } else{

        if(s2[2]=='D'){
            cout<<"00";
            return 0;
        } else if(s2[2]=='F'){
            cout<<"00";
            return 0;
        }else{
            cout<<"1";
        }
    }

    if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'){
        cout<<"1";
    } else if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'){
        cout<<"1";
    } else if(s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
        cout<<"1";
    } else{
        cout<<"0";
    }

    return 0;
}
