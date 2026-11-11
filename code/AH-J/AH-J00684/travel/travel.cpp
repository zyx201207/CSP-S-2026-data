#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a1>>b1>>a2>>b2;
    if(a1!=a2)cout<<"0000";
    else{
        cout<<1;
        if(b1.substr(0,2)!=b2.substr(0,2)){
            cout<<"000";
        }else{
            cout<<1;
            char c=b1[2],d=b2[2];
            if(c>d)swap(c,d);
            if(!(c=='A'&&d=='B'||d=='C'&&c=='A'||c=='B'&&d=='C'||c=='D'&&d=='F')){
                cout<<"00";
            }else{
                cout<<1;
                if(c=='A'&&d=='B'||c=='B'&&d=='C'||c=='D'&&d=='F'){
                    cout<<1;
                }else{
                    cout<<"0";
                }
            }
        }
    }
    return 0;
}
