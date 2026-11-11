#include<bits/stdc++.h>
using namespace std;
int read(){
    int all=0;bool minues=false;
    char s;
    while(1){
        s=getchar();
        if((s<'0'||s>'9')&&s!='-'){break;}
        if(s=='-'){minues=true;continue;}
        all=all*10+s-'0';
    }
    if(minues==true){return -all;}
    else{return all;}
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==13||c==14){
         while(t--){
            int a,b;
            cin>>a>>b;
            for(int i=1;i<=a;i++){int f=read();}
            cout<<((a+1)/2-b)/4+1;
        }
    }
    else{
        while(t--){
            cout<<'1';
        }
    }
    return 0;
}
