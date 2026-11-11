#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,a1,b,b1;
    cin>>a>>a1>>b>>b1;
    if(a==b){
        cout<<1;
        string t=a1.substr(0,2);
        string t1=b1.substr(0,2);
        if(t==t1){
            cout<<1;
            t=a1.substr(2,1);
            t1=b1.substr(2,1);
            if((t>="A"&&t<="C"&&t1>="A"&&t1<="C")||((t=="D"||t=="F")&&(t1=="D"||t1=="F"))){
                cout<<1;
                if((t=="A"&&t1=="B")||(t=="B"&&t1=="A")||(t=="C"&&t1=="B")||(t=="B"&&t1=="C")||(t=="F"&&t1=="D")||(t=="D"&&t1=="F")){
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
    }
    return 0;
}
