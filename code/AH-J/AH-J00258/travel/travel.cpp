#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string a1,b1;
char e,f;
bool f1(char x,char y){
    if((x>='A'&&x<='C'&&y>='A'&&y<='C')||((x=='D'&&y=='F')||(x=='F'&&y=='D'))){
        return 1;
    }
    return 0;
}
bool g(char x,char y){
    if((x==y+1||y==x+1)&&(x!='C'&&y!='D'&&y!='C'&&x!='D')){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>e>>b>>d>>f;
    if(a==b){
        cout<<1;
    }else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(c==d){
        cout<<1;
    }else{
        cout<<0<<0<<0;
        return 0;
    }
    if(f1(e,f)){
        cout<<1;
    }else{
        cout<<0<<0;
        return 0;
    }
    if(g(e,f)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
