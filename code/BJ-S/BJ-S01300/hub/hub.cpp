//Exoplanetary Mirage
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1;
int c,t,n,d,x[N];
int nxt[N],prv[N],dep[N],buk[N];
void fio(const string&str){
#ifndef COMPL
    freopen((str+".in").c_str(),"r",stdin);
    freopen((str+".out").c_str(),"w",stdout);
#endif
}
signed main(){
    fio("hub");
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        // cout<<t<<":------------\n";
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        int lst=1;
        for(int i=1;i<=n;i++){
            dep[i]=0;
            while(lst<n&&x[lst+1]-x[i]<=d)lst++;
            nxt[i]=lst;
        }
        lst=n;
        int ans=0;
        for(int i=n;i>=1;i--){
            if(nxt[i]==i){
                int dps=dep[i+1];
                int m=-1,cl=0,cr=0;
                for(int j=1;j<=dps;j++){
                    if(buk[j]==1){
                        if(m==-1){
                            cr++;
                        }else{
                            cl++;
                        }
                    }else if(buk[j]>=2){
                        if(m!=-1){
                            ans+=(cl+buk[j])*cr;
                            if(buk[j]==2){
                                cr=2+cl;
                                cl=0;
                            }else{
                                m=-1;
                                cl=cr=0;
                            }
                        }else{
                            if(buk[j]==2){
                                m=1;
                            }else{
                                cl=cr=0;
                            }
                        }
                    }
                }
                if(m)ans+=cl*cr;
                for(int j=i+1;j<=lst;j++){
                    buk[dep[j]]=0;
                }
                lst=i;
            }
            buk[dep[i]=dep[nxt[i]]+1]++;
            // cout<<i<<':'<<dep[i]<<'\n';
        }
        int dps=dep[1];
        int m=-1,cl=0,cr=0;
        for(int j=1;j<=dps;j++){
            // cout<<j<<':'<<buk[j]<<'\n';
            if(buk[j]==1){
                if(m==-1){
                    cr++;
                }else{
                    cl++;
                }
            }else if(buk[j]>=2){
                if(m!=-1){
                    // cout<<cl<<' '<<cr<<' '<<j<<'\n';
                    ans+=(cl+buk[j])*cr;
                    if(buk[j]==2){
                        cr=2+cl;
                        cl=0;
                    }else{
                        m=-1;
                        cl=cr=0;
                    }
                }else{
                    if(buk[j]==2){
                        m=1;
                    }else{
                        cl=cr=0;
                    }
                }
            }
        }
        if(m)ans+=cl*cr;
        for(int j=1;j<=lst;j++){
            buk[dep[j]]=0;
        }
        cout<<ans<<'\n';
    }
    return 0;
}