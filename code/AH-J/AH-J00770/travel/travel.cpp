#include<bits/stdc++.h>
using namespace std;
struct person{
    int c,k;
    string s;
};
person r,x;
char i,o;
bool b;

int intToStr(string &s){
    int res=0;
    int i;
    for(i=0;i<s.size()-1;i++){
        res=res*10+(s[i]-'0');
        //cout<<(s[i]-'0')<<" "<<res<<endl;
    }
    return res;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r.c>>r.s;
    cin>>x.c>>x.s;
    r.k=intToStr(r.s);
    r.s=r.s[r.s.size()-1];
    //cout<<r.k<<" "<<r.s<<endl;
    x.k=intToStr(x.s);
    x.s=x.s[x.s.size()-1];
    if(r.c==x.c){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(r.c==x.c&&r.k==x.k){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(((r.s[0]<='C'&&x.s[0]<='C')||(r.s[0]>='D'&&x.s[0]>='D'))&&(r.c==x.c&&r.k==x.k)){
        cout<<"1";
    }else{
        cout<<"0";
    }
    b=((r.s[0]<='C'&&x.s[0]<='C')||(r.s[0]>='D'&&x.s[0]>='D'))&&(r.c==x.c&&r.k==x.k);
    i=r.s[0];
    o=x.s[0];
    if(i>o){
        swap(i,o);
    }
    //cout<<i<<endl;
    //cout<<o<<endl;
    if(b&&(i==o-1)&&i!='C'){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
