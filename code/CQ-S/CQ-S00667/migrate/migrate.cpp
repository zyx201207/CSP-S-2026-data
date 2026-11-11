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

// const int N=5e3+20,inf=LONG_LONG_MAX>>2;
const int N=2e5+20,inf=LONG_LONG_MAX>>2;

int n,d,a[N],f[N],dis[N];

/*
0:no
1:only
2:double
>2
*/


bool check(int i,int j){
    return abs(a[i]-a[j])<=d;
}

void one(){
    n=read(),d=read();
    a[0]=-inf;a[n+1]=inf;
    for(int i=1;i<=n;i++)a[i]=read();
    if(n<=3){
        putchar('0');
        return;
    }
    // for(int i=1;i<=n;i++)a[i]=i;
    int ans=0;
    // int cl=0;
    for(int i=1;i<=n;i++){
        // while(cl<=i&&check(i,cl)==0)cl++;
        memset(dis,0x3f,sizeof(dis));
        memset(f,0,sizeof(f));
        f[i]=1,dis[i]=1;
        int dl=i,dr=i,sum=f[dr];
        for(int l=i-1;l>=1;l--){
            f[l]=0;
            while(check(l,dr)==0)sum-=f[dr],dr--;
            if(dl>dr)dl=dr,sum=f[dr];
            while(dis[dl-1]==dis[dr])dl--,sum+=f[dl];
            f[l]=sum;
            if(sum<=0)break;
            // if(dis[l]>N)break;
            dis[l]=dis[dr]+1;
            ans+=(f[l]==2);
            // cout<<i<<" "<<l<<" "<<dl<<" "<<dr<<" "<<f[l]<<"\n";
            // cerr<<a[l]<<" "<<a[dr]<<" "<<check(l,dr)<<" "<<dis[dl]<<" "<<dis[dr]<<"\n\n";
        }
    }
    // cerr<<">>>>>>>>>>>>>>>>>";
    write(ans);
}

void SubA(){
    n=read(),d=read();
    for(int i=1;i<=n;i++)a[i]=read();
    if(n<=3){
        putchar('0');
        return;
    }
    int k=d/(a[2]-a[1]);
    write(max((int)0,n-2*k+1));
}
int b[N];
void SubB(){
    n=read(),d=read();
    for(int i=1;i<=n;i++)a[i]=read();
    if(n<=3){
        putchar('0');
        return;
    }
    int d1=1,ans=0;
    for(int i=1;i<=n;i++){
        while(d1<n&&check(d1,i)==0)d1++;
        b[i]=d1;
        // cerr<<"<"<<b[i]<<">";
    }
    for(int i=4;i<=n;i++){
        if(i-b[i]==2){
            ans+=(i-2-max(b[i-1],b[i-2]));
            // cerr<<"["<<i<<" "<<ans<<"]";
        }
    }
    write(ans);
}

int c;
signed main(){
    // freopen("migrate6.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    int T=read();
    while(T--){
        if(c==11||c==12){
            SubA();
        }else{
            if(c==13||c==14)SubB();
            else one();
        }
        putchar('\n');
    }
    return 0;
}