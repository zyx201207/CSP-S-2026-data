#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5,M=5010;
int n,c,t,lst,l[N],r[N],f[M][M],cnt[M][M];
ll ans,d,x[N],sub;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        lst=1;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            while(x[i]-x[lst]>d){
                r[lst]=i-1;
                lst++;
            }
            l[i]=lst;
            if(i>1){
                sub=min(sub,x[i]-x[i-1]);
            }
        }
        if(c>10){
            if(sub<d){
                cout<<"0\n";
            }else{
                cout<<max(0ll,n-sub/d*2)<<'\n';
            }
            continue;
        }
        while(lst<=n){
            r[lst++]=n;
        }
        //for(int i=1;i<=n;i++)cout<<i<<':'<<l[i]<<' '<<r[i]<<'\n';
        for(int i=1;i<=n;i++){
            for(int j=1;j+i-1<=n;j++){
                int k=j+i-1;
                if(r[j]>=k){
                    f[j][k]=cnt[j][k]=1;
                }else{
                    f[j][k]=0x3f3f3f3f;
                    for(int l=j+1;l<=r[j];l++){
                        if(f[j][k]>f[l][k]+1){
                            f[j][k]=f[l][k]+1;
                            cnt[j][k]=cnt[l][k];
                        }else if(f[j][k]==f[l][k]+1){
                            cnt[j][k]+=cnt[l][k];
                        }
                    }
                }
                //cout<<j<<' '<<k<<' '<<f[j][k]<<' '<<cnt[j][k]<<'\n';
                if(f[j][k]<0x3f3f3f3f&&cnt[j][k]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
