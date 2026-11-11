#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){cout<<"0000";return 0;}
    else{
        cout<<1;
        int m=(b[0]+'0')*10+(b[1]+'0');
        int n=(d[0]+'0')*10+(d[1]+'0');
        if(m!=n){
            cout<<"000";
            return 0;
        }
        else{
            cout<<1;
            if((b[2]>='D'&&d[2]<'D')||(b[2]<'D'&&d[2]>='D')){
                cout<<"00";
                return 0;
            }
            else{
                cout<<1;
                if(b[2]=='A'&&d[2]=='C')cout<<0;
                else if(b[2]=='C'&&d[2]=='A')cout<<0;
                else cout<<1;
            }
        }
    }
    return 0;
}
