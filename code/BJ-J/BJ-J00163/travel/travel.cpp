#include<bits/stdc++.h>
using namespace std;
#define int long long


bool a,b,c,d;
string c1,c2,c3,c4;

signed main(){
    ios::sync_with_stdio(false);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>c2>>c3>>c4;
    if(c1==c3)a=1;
    int t=(c2[0]-'0'*10+c2[1]-'0');
    int tt=(c4[0]-'0'*10+c4[1]-'0');
    if(t==tt&&a)b=1;
    //cout<<"c2[2]:"<<c2[2]<<" "<<c4[2]<<endl;
    if(b&&a){
        bool t=0,t1=0,ok=0;
        for(auto i='A';i<='C';i++){
            if(c2[2]==i)t=1,ok=1;
            if(c4[2]==i)t1=1,ok=1;
        }
        if(t&&t1){
            c=1;
        }
        if(!ok){
            t=0,t1=0;
            for(auto i='D';i<='F';i++){
                if(c2[2]==i)t=1;
                if(c4[i]==i)t1=1;
            }
            if(t&&t1){
                c=1;
            }
        }


    }
    if(c&&(c2[2]+1==c4[2]||c2[2]-1==c4[2]))d=1;
    cout<<a<<b<<c<<d;

    return 0;
}
