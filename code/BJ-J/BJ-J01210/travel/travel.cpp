#include<bits/stdc++.h>
using namespace std;
int a,b;
string x,y,n,m;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>x>>b>>y;
    n=x[2];
    m=y[2];
    if(a==b){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(a==b){
        if(x[0]==y[0]&&x[1]==y[1]){
            cout<<"1";
        }else{
            cout<<"000";
            return 0;
        }
    }
    if(a==b){
        if(x[0]==y[0]&&x[1]==y[1]){
            if((n=="A"||n=="B"||n=="C")&&(m=="A"||m=="B"||m=="C")){
                cout<<"1";
            }else if((n=="F"||n=="D")&&(m=="F"||m=="D")){
                cout<<"1";
            }else{
                cout<<"00";
                return 0;
            }
        }
    }if(a==b){
        if(x[0]==y[0]&&x[1]==y[1]){
            if((n=="A"&&m=="B")||(n=="B"&&m=="C")||(n=="C"&&m=="B")||(n=="B"&&m=="A")){
                cout<<"1";
            }else if((n=="F"&&n=="D")||(n=="D"&&m=="F")){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }
    }
    return 0;
}
