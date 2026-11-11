#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int n=0,f=1;
    char c=getchar();
    while(c<'0'||'9'<c){
        if(c=='-')f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        n=(n<<3)+(n<<1)+(c^48);
        c=getchar();
    }
    return n*f;
}

inline void write(int x){
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x>9)write(x/10);
    putchar(x%10^48);
    return;
}

int n,d,c,ans;
int a[2000005];
int g[305][305];
int t[305][305];

signed mian1(){
    cin>>n>>d;
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    memset(g,0x3f,sizeof g);
    memset(t,0,sizeof t);
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            if(a[i]-a[j]<=d){
                g[j][i]=1;
                t[j][i]=1;
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=k;++i){
            for(int j=k;j<=n;++j){
                if(g[i][j]>g[i][k]+g[k][j]){
                    g[i][j]=g[i][k]+g[k][j];
                    t[i][j]=0;
                }
                if(g[i][j]==g[i][k]+g[k][j]){
                    t[i][j]+=t[i][k]*t[k][j];
                    t[i][j]=min(3ll,t[i][j]);
                }
            }
        }
    }
    ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            ans+=(t[j][i]==2);
            //cout<<j<<" "<<i<<" "<<g[j][i]<<" "<<t[j][i]<<"\n";
        }
    }
    write(ans);putchar('\n');
    return 0;
}

signed mian2(){
    cin>>n>>d;
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    int gc=a[2]-a[1];
    int temp=d/gc;
    write(max(0ll,n-2*temp+1));
    putchar('\n');
    return 0;
}

signed mian3(){
    cin>>n>>d;
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    for(int i=1;i<=n;++i){

    }
    return 0;
}

signed main(){
    //freopen("migrate.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    int t=read();
    while(t--){
        if(1<=c&&c<=6)mian1();
        else if(11<=c&&c<=12)mian2();
        //else if(11<=c&&c<=12)mian3();
        else puts("0");
    }
    return 0;
}