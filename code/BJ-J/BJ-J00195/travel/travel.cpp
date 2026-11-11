#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x, y, m, n;
char u,v;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    x=(a[0]-'0')*10+a[1]-'0';
    m=(b[0]-'0')*10+b[1]-'0';
    y=(c[0]-'0')*10+c[1]-'0';
    n=(d[0]-'0')*10+d[1]-'0';
    u = b[2], v = d[2];
    if(x == y) {
        if(m == n){
            if(u>='A'&&u<='C'&&v>='A'&&v<='C'){
                if(u-v==1||v-u==1){
                    cout<<"1111";
                    return 0;
                }
                else{
                    cout<<1110;
                    return 0;
                }
            }
            else if((u=='D'&&v=='E')||(u=='E'&&v=='D')){
                cout<<"1111";
                return 0;
            }
            else{
                cout<<"1100";
                return 0;
            }
        }
        else{
            cout<<"1000";
            return 0;
        }
    }
    else{
       cout<<"0000";
       return 0;
    }
    return 0;
}
