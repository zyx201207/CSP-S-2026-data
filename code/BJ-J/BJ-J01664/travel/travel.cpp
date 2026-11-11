#include<bits/stdc++.h>
using namespace std;
struct ticket{
    int a;
    char c;
};
int c1,c2;
ticket s1,s2;
int flag=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1.a>>s1.c>>c2>>s2.a>>s2.c;
    if(s1.c>='A'&&s1.c<='C'&&s2.c>='A'&&s2.c<='C'){
        flag=1;
    }
    if(s1.c=='D'&&s1.c=='F'&&s2.c=='D'&&s2.c=='F'){
        flag=2;
    }
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if((c1==c2)&&(s1.a==s2.a)){
        cout<<1;
    }else{
        cout<<0;
    }
    if((c1==c2)&&(s1.a==s2.a)&&(flag==1||flag==2)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(flag==2){
        cout<<1;
    }else if(flag==1&&s1.a==s2.a&&abs(s1.c-s2.c)==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}