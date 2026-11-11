#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    string tmp=s1.substr(0,2);
    string tmp2=s2.substr(0,2);
    if(c1==c2&&tmp==tmp2){
        cout<<1;
    }else{
        cout<<0;
    }
    string x=s1.substr(2,1);
    string y=s2.substr(2,1);
    bool flag=0;
    if(c1==c2&&tmp==tmp2){
        if(x=="A"||x=="B"||x=="C"){
            if(y=="A"||y=="B"||y=="C"){
                cout<<1;
                flag=1;
            }else{
                cout<<0;
            }
        }else{
            if(y=="D"||y=="E"){
                cout<<1;
                flag=1;
            }else{
                cout<<0;
            }
        }
    }else{
        cout<<0;
    }
    if(c1==c2&&tmp==tmp2&&flag){
        char c=s1[2],d=s2[2];
        if(c=='A'||c=='C'){
            if(d=='B'){
                cout<<1;
            }else{
                cout<<0;
            }
        }else if(c=='B'){
            if(d=='A'||d=='C'){
                cout<<1;
            }else{
                cout<<0;
            }
        }else if(c=='D'||c=='E'){
            if(d=='D'||d=='E'){
                cout<<1;
            }else{
                cout<<0;
            }
        }
    }else{
        cout<<0;
    }
    return 0;
}
