#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char c1,c2;
    cin>>a>>b>>c1>>c>>d>>c2;
    if(a!=c)cout<<"0000"<<endl;
    else{
        if(b!=d)cout<<"1000"<<endl;
        else if((c1>'C' && c2<='C' )||(c1<='C' && c2>'C'))cout<<"1100"<<endl;
        else if(max(c1,c2)-min(c1,c2)!=1)cout<<"1110"<<endl;
        else cout<<"1111"<<endl;
    }
    return 0;
}
