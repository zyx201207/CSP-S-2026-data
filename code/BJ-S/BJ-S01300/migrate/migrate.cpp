//Exoplanetary Mirage
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1;
int c,t,n,d,x[N];
int nxt[N],prv[N],degxt[N],degrv[N];
int val[N],var[N];
void fio(const string&str){
#ifndef COMPL
    freopen((str+".in").c_str(),"r",stdin);
    freopen((str+".out").c_str(),"w",stdout);
#endif
}
signed main(){
    fio("migrate");
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        // cout<<t<<":------------\n";
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        int lst=1;
        for(int i=1;i<=n;i++){
            while(lst<n&&x[lst+1]-x[i]<=d)lst++;
            nxt[i]=lst;
        }
        lst=n;
        for(int i=n;i;i--){
            while(lst>1&&x[i]-x[lst-1]<=d)lst--;
            prv[i]=lst;
        }
        for(int i=1;i<=n;i++){
            // cout<<prv[i]<<"<-"<<i<<"->"<<nxt[i]<<"\n";
        }
        for(int i=1;i<=n;i++){
            val[i]=var[i]=0;
            degxt[i]=degrv[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(nxt[i]!=i){
                degxt[nxt[i]]++;
                if(prv[nxt[i]]==i)degxt[nxt[i]]+=degxt[i];
            }
        }
        for(int i=n;i>=1;i--){
            if(prv[i]!=i){
                degrv[prv[i]]++;
                if(nxt[prv[i]]==i)degrv[prv[i]]+=degrv[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(nxt[i]>=i+2)var[nxt[i]]+=(degxt[i]+1);
        }
        for(int i=n;i>=1;i--){
            if(prv[i]<=i-2)val[prv[i]]+=(degrv[i]+1);
        }
        for(int i=1;i<=n;i++){
            // cout<<i<<':'<<'\n';
            // cout<<degxt[i]<<' '<<degrv[i]<<'\n';
            // cout<<val[i]<<' '<<var[i]<<'\n';
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=val[i]*var[i+1];
        }
        cout<<ans<<'\n';
    }
    return 0;
}