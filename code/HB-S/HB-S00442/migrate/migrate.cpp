#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;

namespace shizuru_nakatsu{
    int n;ll d;
    ll x[2000005];
    int l[2000005],r[2000005];
    ll cc[2000005],dd[2000005];
    unordered_map<ll,int>mp1,mp2;
    ll mk(ll x,int y){
        return x*30000000ll+y;
    }
    void init(){mp1.clear();mp2.clear();
        cin>>n>>d;
        l[0]=1;
        for(int i=1;i<=n;i++){cc[i]=0;dd[i]=0;
            cin>>x[i];
            l[i]=l[i-1];
            while(x[i]-x[l[i]]>d&&l[i]<n){
                l[i]++;
            }
        }
        r[n+1]=n;
        for(int i=n;i>=1;i--){
            r[i]=r[i+1];
            while(x[r[i]]-x[i]>d&&r[i]>1){
                r[i]--;
            }
        }
        // for(int i=1;i<=n;i++){
        //     printf("[%lld,%lld]\n",l[i],r[i]);
        // }
    }
    ll dis(int i,int j){
        if(j<i)swap(i,j);
        return x[j]-x[i];
    }
    bool conn(int x,int y){
        return dis(x,y)<=d;
    }
    void my_love(){
        ll ans=0;int ct=0;
        for(int i=2;i+1<n;i++){
            int l1=l[i+1],r1=min(i-1,l[i+2]-1),l2=max(i+2,r[i-1]+1),r2=r[i];
            if(l1>r1||l2>r2)continue;
            int l3=l1,r3=r1,l4=l2,r4=r2;
            cc[i]=r1-l1+1;
            int now=l1;int lst=i,C=0;
            while(1){
                int pre=now;
                int lp=l[pre],rp=min(pre-1,l[pre+1]-1);
                // printf("%d %d %d\n",i,lp,rp);
                if(lp==rp){
                    if(now<=1)break;
                    if(conn(now-1,lst)){
                        now--;
                        int lpp=l[now+1];
                        int rpp=min(now-1,l[now+2]-1);
                        // printf("%d %d %d %d\n",lp,rp,lpp,rpp);
                        if(lpp<=rpp&&rpp<=rp&&lpp>=lp){
                            if(rpp==rp)
                            rp=min(rp,lpp-1);
                            else lp=max(lp,rpp+1);
                        }
                        now++;break;
                    }
                }
                // if(lp==rp)C=1;
                // else C=0;
                if(lp>rp)break;
                if(mp1.count(mk(lp,rp))){
                    cc[i]+=mp1[mk(lp,rp)];
                    break;
                }
                cc[i]+=rp-lp+1;
                now=lp;ct++;
            }
            mp1[mk(l1,r1)]=cc[i];
        }
        for(int i=n-2;i>1;i--){
            int l1=l[i+1],r1=min(i-1,l[i+2]-1),l2=max(i+2,r[i-1]+1),r2=r[i];
            if(l1>r1||l2>r2)continue;
            int l3=l1,r3=r1,l4=l2,r4=r2;
            // printf("%d %d %d %d\n",l1,r1,l2,r2);
            dd[i]=r2-l2+1;
            int lst=i+1;
            int now=r2,C=0;
            while(1){
                if(now>=n)break;
                int pre=now;
                int lp=max(pre+1,r[pre-1]+1),rp=r[pre];
                // printf("%d %d %d\n",i,lp,rp);
                if(lp==rp){
                    if(conn(lst,now+1)){
                        int lpp=max(now+2,r[now-1]+1);
                        int rpp=r[now];
                        // printf("%d %d %d %d\n",lp,rp,lpp,rpp);
                        if(lpp<=rpp&&rpp<=rp&&lpp>=lp){
                            if(rpp==rp)
                            rp=min(rp,lpp-1);
                            else lp=max(lp,rpp+1);
                        }break;
                    }
                }
                // if(lp==rp)C=1;
                // else C=0;
                if(lp>rp)break;
                if(mp2.count(mk(lp,rp))){
                    dd[i]+=mp2[mk(lp,rp)];
                    break;
                }
                dd[i]+=rp-lp+1;
                lst=now;
                now=rp;ct++;
            }
            mp2[mk(l2,r2)]=dd[i];
            ans+=cc[i]*dd[i];
            // printf("%d %d %d\n",i,cc[i],dd[i]);
            // if(l1!=l3||r2!=r4){
            // printf("%d %d %d %d\n",l3,r3,l4,r4);
            // printf("%d %d %d %d\n",l1,r1,l2,r2);
            // }
        }
        cout<<ans<<"\n";
        // cout<<ans<<endl;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int C,T=1;
    cin>>C>>T;
    while(T--){
        shizuru_nakatsu::init();
        shizuru_nakatsu::my_love();
    }
    return 0;
}