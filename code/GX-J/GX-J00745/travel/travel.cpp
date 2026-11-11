#include<bits/stdc++.h>;
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int v1=0,v2=0,v3=0,v4=0;
    cin>>a>>b>>c>>d;

    if(a==c){
        v1++;
    }
    if(v1==1&&b[0]==d[0]&&b[1]==d[1]){
        v2++;
    }
    if(v2==1&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))){
        v3++;
    }
    if(v3==1&&(b[2]+1==d[2]||b[2]-1==d[2])){
        v4++;
    }

    cout<<v1<<v2<<v3<<v4;
    return 0;
}
