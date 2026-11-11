#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=500002;
ll a[maxn],qa[maxn];
ll n,m,ans=0,maxa=-1000000000001,mina=1000000000001;
bool check(){
    for(int i=2;i<=n;i++)if(a[i]!=a[i-1]+1)return 0;
    else return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
        mina=min(mina,a[i]);
    }
    if(n>5000&&maxa<=100&&mina>=-100){
        ll sl[221],cj[221],qcj[221];
        memset(sl,0,sizeof(sl));
        for(int i=1;i<=n;i++)sl[a[i]+100]++;
        ll l=1,r=maxa;
        for(int i=mina;i<=maxa;i++){
            ll need=0,bring=0;
            for(int j=i;j>=mina;j--){
                need+=sl[j+100]*(i-j);
                if(need<=m){
                    bring+=sl[j+100];
                    ans=max(ans,bring);
                }
                else{
                    if((i-j)!=0)ans=max(ans,(m-need)/(i-j)+bring);
                    break;
                }
            }
        }
    }else if(n>5000&&check()){
        int jg=0;
        for(jg=0;(2+2*jg)*jg/2<=m;jg++);
        ans=jg*2-1;
        if((m-(2+2*jg)*jg/2)>=jg)ans++;
    }else{
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)qa[i]=qa[i-1]+a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(a[j])*(j-i+1)-(qa[j]-qa[i-1])<=m){
                    ans=max(ans,(ll)j-i+1);
                }else break;
            }
        }
    }
    cout<<ans;
    return 0;
}
//14:41~15:04 0->45
//14:41~16:20 45->40
//16:20~16:30 40->60
