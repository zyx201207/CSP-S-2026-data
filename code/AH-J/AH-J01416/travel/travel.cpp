#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=1;i<=4;i++){
        if(a!=c){
            cout<<"0000";
            return 0;
        }else if(a==c)  cout<<"1";
        if(b.size()+1!=d.size()){
            cout<<"000";
                return 0;
        }else if((char)b.size()+1==d.size()){
            cout<<"111";
            return 0;
        }
}

    return 0;
}
