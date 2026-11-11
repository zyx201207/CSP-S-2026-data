#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=2e5+10;
int n,m,a[N];
int pre[N];
int suf[N];
int maxn;
int ans;
bool check(int mid){
    int cnt=0;
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=0;j<30;j++)
            if(((a[i]>>j)&1)&&((mid>>j)&1))res|=(1<<j);
        cnt+=(res==mid);
        // cerr<<mid<<"&"<<a[i]<<"="<<res<<"\n";
    }
    return cnt>=m;
}
int power(int x,int y){
    int res=1;
    while(y){
        if(y&1)res*=x;
        x*=x;
        y>>=1;
    }
    return res;
}
int getrand(int l,int r){
    return rand()%(r-l+1)+l;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)maxn=max(maxn,a[i]=read());
    if(n<=20||n*maxn<=(int)9e8){
        for(int i=maxn;i>=0;i--)
            if(check(i)){ans=i;break;}
        printf("%lld\n",ans);
    }else if(m==1){
        printf("%lld\n",maxn);
    }else if(m==2){
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
        printf("%lld\n",ans);
    }else if(m==n-1){
        pre[0]=(1<<20)-1;for(int i=1;i<=n;i++)pre[i]=pre[i-1]&a[i];
        suf[n+1]=(1<<20)-1;for(int i=n;i>=1;i--)suf[i]=suf[i+1]&a[i];
        for(int i=1;i<=n;i++)ans=max(ans,pre[i-1]&suf[i+1]);
        printf("%lld\n",ans);
    }else{
        bool flg1=(power(2,log2(n))==n),flg2=1;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            flg1&=(a[i]==i-1);
            int sum=a[i]+1;
            flg2&=(power(2,log2(sum))==sum);
        }
        if(flg1||flg2){
            printf("%lld\n",a[n-m+1]);
        }else{
            srand(time(0));
            int maxx=0,ans=0;
            for(int i=1;i<=2000;i++){
                int j=getrand(maxx,maxn);
                if(check(j))ans=j;
                maxx=j;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
