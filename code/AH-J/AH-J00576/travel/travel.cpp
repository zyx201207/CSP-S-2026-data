#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a,b;
char c,d;
bool f(char a,char b){
    if(int(a)<='C'&&int(b)<='C'||int(a)>='D'&&int(b)>='D')
        return 1;
    return 0;
}
bool s(char a,char b){
    if(int(a)+1==int(b)||int(a)-1==int(b))
        return 1;
    return 0;
}
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>n>>a>>c>>m>>b>>d;
    if(n==m) cout<<1;
    else cout<<0;
    if(n==m&&a==b) cout<<1;
    else cout<<0;
    if(n==m&&a==b&&f(c,d)) cout<<1;
    else cout<<0;
    if(n==m&&a==b&&f(c,d)&&s(c,d)) cout<<1;
    else cout<<0;
    return 0;
}
//Trick||Treat!
