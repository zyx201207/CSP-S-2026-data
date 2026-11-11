#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a1,b1,a2,b2;
char c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    if(a1!=a2){
        cout<<"0000";
        return 0;
    }
    else{
        if(b1!=b2){
            cout<<"1000";
            return 0;
        }
        else{
            if(!(c1+c2=='D'+'F'||c1+c2<='B'+'C')){
                cout<<"1100";
                return 0;
            }
            else{
                if(!(c1-c2==1||c2-c1==1||c1+c2=='D'+'F')){
                    cout<<"1110";
                    return 0;
                }
                else cout<<"1111";
            }
        }

    }
    return 0;
}
