#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
#define int long long
#define gc_u getchar_unlocked
#define pc_u putchar_unlocked
const int N=2e6+5,Inf=3e18+5;
/*void read(int &res){
    res=0;
    int f=1;
    char c=gc_u();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=gc_u();
    }
    while(isdigit(c))res=(res<<1)+(res<<3)+c-48,c=gc_u();
    res*=f;
}
void write(int res){
    if(!res){
        pc_u('0');pc_u('\n');
        return ;
    }
    int cnt=0,cc[20];
    while(res){
        cc[++cnt]=res%10;
        res/=10;
    }
    while(cnt)pc_u(cc[cnt--]+48);
    pc_u('\n');
}*/
int cid,T,n,d,x[N],pre[N],suf[N],ans;
void solve(){
    cin>>n>>d;
    x[n+1]=Inf,x[0]=-Inf;
    ans=pre[0]=suf[0]=pre[n+1]=suf[n+1]=0;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        pre[i]=suf[i]=0;
    }
    for(int i=2;i<=n;i++){
        if(x[i+1]-x[i-1]>d&&x[i]-x[i-1]<=d)pre[i]=pre[i-1]+1;
    }
    for(int i=n-1;i>=1;i--){
        if(x[i+1]-x[i-1]>d&&x[i+1]-x[i]<=d)suf[i]=suf[i+1]+1;
    }
    for(int i=1;i<=n;i++){
        int st=upper_bound(x+i,x+n+1,x[i]+d)-x,en=lower_bound(x+i,x+n+1,x[i]+2*d)-x-1;
        //cout<<st<<" "<<en<<" "<<pre[i]<<" "<<suf[i]<<endl;
        if(st>n)continue;
        for(int j=st;j<=en;j++){
            int res=0;
            for(int k=i+1;k<j&&x[k]-x[i]<=d;k++){
                if(x[j]-x[k]<=d)res++;
            }
            //cout<<i<<" "<<j<<" "<<res<<endl;
            if(res==2)ans+=(pre[i]+1)*(suf[j]+1);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>cid>>T;
    while(T--)solve();
}
