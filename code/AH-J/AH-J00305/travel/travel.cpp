#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>x>>c>>d>>y;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(b!=d){
        cout<<"000";
        return 0;
    }
    cout<<1;
    bool f1=(x>='A'&&x<='C'),f2=(y>='A'&&y<='C');
    if(f1!=f2){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(abs(x-y)!=1){
        cout<<0;
        return 0;
    }
    cout<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
