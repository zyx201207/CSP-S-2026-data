#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(long long tt=0;tt<t;tt++){
      //  cout<<c<<endl;
        cin>>n>>d;
        for(long long i=0;i<n;i++) cin>>a[i];
        if(c==11 || c==12 ){
            long long cha=a[1]-a[0];
            if((2*cha)>d) cout<<0<<endl;
            else{
                long long maxbu=d/cha;
                if((2*maxbu)>n) cout<<0<<endl;
                else{
                    long long ans=n-2*maxbu+1;
                    cout<<ans<<endl;

                }

            }
        }else if(c==13 || c==14){
            long long ans=0;
            long long dao;
            for(long long i=0;i<n;i++){
                if((a[i]-a[0])<=d && (a[n-1],a[i])<=d){
                    dao=i;
                    break;
                }
            }
            for(long long i=0;i<dao;i++){
                for(long long j=dao+1;j<n;j++){
                    if((a[j]-a[i])>2*d) break;
                    long long tmp=0;
                    for(long long k=i+1;k<=j-1;k++){
                        if((a[k]-a[i])>d) break;
                        if(k==dao) continue;
                        if((a[k]-a[i])<=d && (a[j]-a[k])<=d) tmp++;
                        if(tmp>1) break;
                    }
                    if(tmp==1) ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
