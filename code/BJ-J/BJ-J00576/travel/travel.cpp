#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
bool a=false,b=false,c=false,d=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx){
        a=true;
        if(sr[0]==sx[0] && sr[1]==sx[1]){
            b=true;
            if((sr[2]>='A' && sr[2]<='C') && (sx[2]>='A' && sx[2]<='C') || (sr[2]=='D' || sr[2]=='F') && (sx[2]=='D' || sx[2]=='F')){
                c=true;
                d=true;
                if((sr[2]=='A' && sx[2]=='C') ||(sr[2]=='C' && sx[2]=='A')){
                    d=false;
                }
            }
        }
    }
    cout<<a<<b<<c<<d<<'\n';
    return 0;
}
