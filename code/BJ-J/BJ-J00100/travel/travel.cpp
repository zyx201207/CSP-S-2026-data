#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    bool a=(s1==t1);
    bool b=(s2.substr(0,2)==t2.substr(0,2));
    if(!a){
        cout<<0<<0<<0<<0;
        return 0;
    }
    else{
        if(!b){
            cout<<1000;
            return 0;
        }
    }
    cout<<11;
    char c=s2[2],d=t2[2];
    if(abs(c-d)!=1){
        if(c=='F'&&d=='D'||c=='D'&&d=='F'){
            cout<<11;
        }
        else{
            if(c=='A'&&d=='C'||c=='C'&&d=='A'){
                cout<<10;
            }
            else{
                cout<<0<<0;
            }
        }
    }
    else{
        if(c=='C'&&d=='D'||c=='D'&&d=='C'){
            cout<<0<<0;
        }
        else{
            cout<<11;
        }
    }
    return 0;
}