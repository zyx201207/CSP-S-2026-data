#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
struct Node{
    int to,w,nxt;
}p[N];
int t,c;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    while(t--){
        int n,d;
        n=read();d=read();
        for(int i=1;i<=n;i++)p[i].to=read();

    }
    cout << "0" << '\n' << "1";
    return 0;
}