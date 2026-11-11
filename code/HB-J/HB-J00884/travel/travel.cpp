#include <iostream>
#include <string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string rz,xz,rc,xc;
    cin>>rc>>rz>>xc>>xz;
    int a=0,b=0,c=0,d=0;
    if(rc==xc){
        a=1;
        if(rz[0]==xz[0] && rz[1]==xz[1]){
            b=1;
            if(rz[2]-xz[2]<=2 && rz[2]-xz[2]>=-2){
                c=1;
                if((rz[2]-xz[2]==1 || rz[2]-xz[2]==-1) && (xz[2]!='D' ||xz[2]||'C')){
                    d=1;
                }
            }
        }
    }
    cout<<a<<b<<c<<d;
    fclose(stdin);
    fclose(stdout);
return 0;}
