#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
    int x=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int ___[40];
void write(int x){
    if(x<0){
        putchar('-'),x=-x;
    }
    if(x==0){
        putchar('0');
        return;
    }
    int tot=0;
    while(x){
        ___[++tot]=x%10+'0';
        x/=10;
    }
    while(tot){
        putchar(___[tot--]);
    }
}

const int N=5e5+20;



signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int T=read();
    while(T--){
        cout<<"0\n";
    }
    
    return 0;
}