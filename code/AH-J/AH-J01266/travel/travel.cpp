#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            char c1=b[2],c2=d[2];
            if(c1=='A'&&(c2=='B'||c2=='C')||c1=='B'&&(c2=='A'||c2=='C')||c1=='C'&&(c2=='A'||c2=='B')||c1=='D'&&c2=='F'||c1=='F'&&c2=='D'){
                cout<<1;
                if(abs((int)(c1-c2))==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
