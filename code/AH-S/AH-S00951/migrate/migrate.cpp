#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define MAXN 2000010
using namespace std;

int cc,t;
ll n,d;
ll x[MAXN],c[MAXN],sum[MAXN];
ll th[MAXN],cnt,cth[MAXN];
bool fth[MAXN];
bool flf[MAXN],flb[MAXN];

ll qh(ll l,ll r){ return sum[r]-sum[l-1]; }

ll check(ll x,ll len){
    if(qh(x-len+1,x)<=d) return 0;
    for(int i=x-len+1;i<=x;i++){
        if(qh(x-len+1,i)>d) continue;
        if(qh(i,x)>d) continue;
        return i;
    }
    return 0;
}

bool checkf(ll x,ll len,ll i){
    if(qh(x-len,i-1)>d) return false;
    if(qh(i,x)>d) return false;
    return true;
}

bool checkb(ll x,ll len,ll i){
    if(qh(x-len+1,i)>d) return false;
    if(qh(i+1,x+1)>d) return false;
    return true;
}

ll calc(ll nq1l,ll nq1r,ll kd1,ll nq2l,ll nq2r,ll kd2){
    return (nq1r-nq1l+1-kd1)*(nq2r-nq2l+1-kd2);
}

void runr(){
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        ll dec=x[2]-x[1];
        ll len=(d/dec)*2-1;
        if(len<=2) cout<<0<<endl;
        else cout<<max((ll)0,(n-1)-len+1)<<endl;
    }
    return ;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>cc>>t;
    if(cc==11||cc==12){
        runr();
        return 0;
    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i!=1) c[i]=x[i]-x[i-1];
            if(i!=1) sum[i]=sum[i-1]+c[i];
            //if(c[i]>d) no[i]=true;
        }
        cnt=0;
        memset(fth,false,sizeof(fth));
        memset(flf,false,sizeof(flf));
        memset(flb,false,sizeof(flb));
        for(ll i=2;i<=n;i++){
            if(i>=4){
                for(ll j=3;j<n;j++){
                    ll pos=check(i,j);
                    if(pos){
                        th[++cnt]=i;
                        cth[cnt]=j;
                        //cth1[cnt]=pos;
                        if(i-j-1>0&&checkf(i,j,pos)) flf[cnt]=true;
                        if(i<n&&checkb(i,j,pos)) flb[cnt]=true;
                    }
                }
                //th[++cnt]=i;
                /*if(i>4&&checkf(i)){
                    flf[cnt]=true;
                    //cout<<i<<endl;
                }
                if(i<n&&checkb(i)) flb[cnt]=true;*/
            }
            if(c[i]>d){
                th[++cnt]=i;
                fth[cnt]=true;
            }
        }
        ll ans=0;
        //cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++){
            if(fth[i]) continue;
            ll kdl=0,nowl=0,kdr=0,nowr=0;
            if(!flf[i]){
                for(int j=i-1;j>=1;j--){
                    if(fth[j]){
                        nowl=th[j];
                        break;
                    }
                    if(!flf[j]&&!flb[j]){
                        nowl=th[j]-cth[j]+1;
                        break;
                    }
                    if(flf[j]) kdl++;
                }
                if(nowl==0) nowl=1;
                //cout<<"true"<<endl;
            } else { nowl=th[i]-cth[i]; }
            if(!flb[i]){
                for(int j=i+1;j<=cnt;j++){
                    if(fth[j]){
                        nowr=th[j]-1;
                        break;
                    }
                    if(!flf[j]&&!flb[j]){
                        nowr=th[j]-1;
                        break;
                    }
                    if(flb[j]) kdr++;
                }
                if(nowr==0) nowr=n;
            } else { nowr=th[i]; }
            //cout<<nowl<<" "<<th[i]<<" "<<nowr<<" "<<calc(nowl,th[i]-3,kdl,th[i],nowr,kdr)<<endl;
            ans=ans+calc(nowl,th[i]-cth[i],kdl,th[i],nowr,kdr);
        }
        cout<<ans<<endl;
    }
    return 0;
}
