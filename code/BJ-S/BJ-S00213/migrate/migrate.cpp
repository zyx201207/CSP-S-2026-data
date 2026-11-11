#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int C,n,pre[N];
ll d,a[N],f[N];
int tag[N];
void solve(){
    cin>>n>>d;
    for(int i=0;i<=n;i++)f[i]=pre[i]=tag[i]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    int p=1;
    for(int i=1;i<=n;i++){
        while(p<i&&a[i]-a[p]>d)p++;
        pre[i]=p;
    }
    ll ans=0;
    int lim=1;
    if(C==11||C==12)lim=n;
    for(int i=lim;i<=n;i++){
        int l=pre[i],r=i-1;
        for(int j=l;j<=min(l+2,r);j++)f[j]=1;
        while(l<=r){
            
            if(!l||!r||l==1)break;
            if(f[l]>2)break;
            //cout<<"RD "<<i<<" "<<f[l]<<" "<<l<<" "<<r<<endl;
            int nl=pre[l],nr=l-1;
            ll sum=0;
            for(int k=l;k<=r;k++){
                sum+=f[k];
                if(sum==2){
                    int lt;
                    if(k<r)lt=pre[k+1]-1;
                    else lt=l-1;
                    if(lt>=pre[k]){
                        ans+=lt-pre[k]+1;
                        if(C==11||C==12){
                            tag[n-pre[k]+2]--,tag[n-lt+1]++;
                            //cout<<"RG "<<n-lt+1<<" "<<n-pre[k]+1<<endl;
                        }
                        //cout<<"SUC "<<pre[k]<<" "<<lt<<"\n";
                    }
                }
                if(sum>2){
                    //nr=pre[k]-1;
                    break;
                }
            }         
            sum=0;
            for(int k=nl;k<=min(nl+2,nr);k++)f[k]=0;
            for(int k=l;k<=r;k++){
                sum+=f[k];
                
                for(int p=pre[k];p<=min(nl+2,nr);p++)f[p]+=f[k];
                if(sum>2)break;
            }   
            l=nl;r=nr;
            //break;
        }
    }
    if(C==11||C==12){
        ans=0;
        for(int i=1;i<=n;i++){
            tag[i]+=tag[i-1];
            if(tag[i])ans+=(n-i+1);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>C>>t;
    while(t--)solve();
    //cout<<"STEP "<<res<<endl;
    return 0;
}