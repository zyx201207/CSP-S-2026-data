#include<bits/stdc++.h>
using namespace std;
char a1,b1,c1,d1,e1,a2,b2,c2,d2,e2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>c1>>d1>>e1>>a2>>b2>>c2>>d2>>e2;
    if(a1!=a2 || b1!=b2){
        cout<<"0000"<<endl;
        return 0;
    }
    if(c1!=c2 || d1!=d2){
        cout<<"1000"<<endl;
        return 0;
    }
    if(((e1=='F' || e2=='F') && (e1=='D' || e2=='D')) || (e1!='F' && e2!='F' && e1!='D' && e2!='D')){
        if(e1-1==e2 || e1+1==e2)    cout<<"1111"<<endl;
        else                        cout<<"1110"<<endl;
    }
    else    cout<<"1100"<<endl;
    return 0;
}