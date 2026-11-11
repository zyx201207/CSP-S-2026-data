#include <bits/stdc++.h>
using namespace std;
string a,b,m,n;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>m>>n;
    if(a!=m){
        cout<<"0000"<<endl;
        return 0;
    }else{
        cout<<1;
    }
    if(b[0]==n[0]&&b[1]==n[1]){
        cout<<1;
        if((b[2]=='A'&&n[2]=='B')||(b[2]=='B'&&n[2]=='C')||(b[2]=='A'&&n[2]=='C')||(b[2]=='D'&&n[2]=='F')||(n[2]=='A'&&b[2]=='B')||(n[2]=='B'&&b[2]=='C')||(n[2]=='A'&&b[2]=='C')||(n[2]=='D'&&b[2]=='F')){
            if((b[2]=='A'&&n[2]=='C')||(n[2]=='A'&&b[2]=='C')){
                cout<<"10"<<endl;
            }else{
                cout<<"11"<<endl;
            }
        }else{
            cout<<"00"<<endl;
        }
    }else{
        cout<<"000"<<endl;
    }

    return 0;
}
