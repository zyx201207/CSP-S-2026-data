#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<"1";
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<"1";
            int s1=int(c[2]);
            int s2=int(d[2]);
            if((s1<=67&&s2<=67)||(s2>67&&s1>67)){
                cout<<"1";
                if(abs(s1-s2)==1||((s1==68&&s2==70)||(s1==70&&s2==68)))cout<<"1";
                else cout<<"0";
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
