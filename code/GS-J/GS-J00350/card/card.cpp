#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string aa("ABCDF");
    int d,e;
    string f;
    string g;
    cin>>d>>f>>e>>g;
    if(d==e){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    int h,z;
    for(int i=0;i<5;i++){
        if(f[2]==aa[i]){
           h=i+1;
        }
    }
    for(int i=0;i<5;i++){
        if(g[2]==aa[i]){
            z=i+1;
        }
    }
    if(h!=z){
        if(f[0]==g[0] and f[1]==g[1]){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    else{
        cout<<"0";
    }
    if(f[0]==g[0] and f[1]==g[1]){
        if(h!=z){
            if(h<=3 and z<=3 or h>=4 and z>=4){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
        else{
            cout<<"0";
        }
    }
    else{
        cout<<"0";
    }
    if(f[0]==g[0] and f[1]==g[1]){
        if(h<=3 and z<=3 or h>=4 and z>=4){
            if(h+1==z or h-1==z){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
        else{
            cout<<"0";
        }
    }
    else{
        cout<<"0";
    }
    return 0;
}
