#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    long long c , d , a , b;
    char e , f;
    cin>>c>>a>>e>>d>>b>>f;
    if(c==d){
        cout<<1;
    }else{
        cout<<0;
    }
    if((a==b)&&(c==d)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(((e<'D'&&f<'D')||(e>'C'&&f>'C'))&&(a==b)&&(c==d)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(((char)(e-1)==f||(char)(e+1)==f)&&((e<'D'&&f<'D')||(e>'C'&&f>'C'))&&(a==b)&&(c==d)){
        cout<<1;
    }else{
        cout<<0;
    }
    cout<<endl;
    return 0;
}
