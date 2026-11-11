#include<bits/stdc++.h>
#define int long long
// #define ll long long
using namespace std;
const int N=2e6+7;
int c,t;
int n,d;
int x[N];
inline int Calc(int s){
    static int Dis[N],f[N],cnt[N];
    for(int i=0;i<=n;i++)Dis[i]=2e6+7,cnt[i]=0;
    int lst=s,r=n,Cur=1;
    Dis[s]=0;
    for(int i=s+1;i<=n;i++){
        if(x[i]-x[i-1]>d){
            r=i-1;
            break;
        }
        if(x[i]-x[lst]>d){
            lst=i-1;Cur++;
        }
        Dis[i]=Cur;
    }
    // cout<<s<<endl;
    // for(int i=s;i<=r;i++){
    //     cout<<Dis[i]<<" ";
    // }
    // cout<<endl;
    f[s]=1;
    cnt[0]++;
    int l=s;
    int Ans=0;
    for(int i=s+1;i<=r;i++){
        while(x[i]-x[l]>d){
            cnt[Dis[l]]-=f[l];
            l++;
        }
        f[i]=cnt[Dis[i]-1];
        f[i]=min(f[i],3ll);
        Ans+=(f[i]==2);
        cnt[Dis[i]]+=f[i];
    }
    return Ans;
}
inline void slv10(){
    int Ans=0;
    for(int i=1;i<=n;i++)Ans+=Calc(i);
    cout<<Ans<<endl;
    return;
}
inline void slv12(){
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int B=x[2]-x[1];
    if(B>d){
        cout<<0<<endl;
        return;
    }
    d=d/B;
    if(d==1){
        cout<<0<<endl;
        return;
    }
    cout<<max(n-2*d+1,0ll)<<endl;
    return;
}
inline void slv14(){
    static int LM[N],RM[N];
    static int CL[N],CR[N];
    for(int i=1;i<=n;i++)CL[i]=CR[i]=0;
    int p=1;
    for(int i=1;i<=n;i++){
        while(p<n&&x[p+1]-x[i]<=d)p++;
        RM[i]=p;
    }
    p=n;
    for(int i=n;i>=1;i--){
        while(p>1&&x[i]-x[p-1]<=d)p--;
        LM[i]=p;
    }
    for(int i=1;i<=n;i++){
        if(i>LM[i]+1)CL[LM[i]]++;
        if(i<RM[i]-1)CR[RM[i]]++;
    }
    int Ans=0;
    for(int i=1;i<=n;i++)Ans+=CL[i]*CR[i+1];
    cout<<Ans<<endl;
    return;
}
inline void slv(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    if(c<=10)slv10();
    else if(c<=12)slv12();
    else if(c<=14)slv14();
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)slv();
    return 0;
}