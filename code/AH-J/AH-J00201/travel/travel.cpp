#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    string x="",y="";
    char n=b[2],m=d[2];
    for(int i=0;i<2;i++){
        x+=b[i];
        y+=d[i];
    }
    if(x!=y){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(n<='C'&&m>'C'||n>'C'&&m<='C'){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(n-m==1||n-m==-1){
        cout<<1;
    }else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
