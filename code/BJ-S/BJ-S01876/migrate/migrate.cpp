#include<iostream>
#include<algorithm>
using namespace std;
long long x[2000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c==11||c==12){
            long long tar=d/(x[2]-x[1]);
            if(tar==0||tar==1){
                cout<<0<<'\n';
                continue;
            }
            long long sz=tar*2-1;
            long long ans=n-tar*2+1;
            cout<<max(0ll,ans)<<'\n';
            continue;
        }
        if(c==13||c==14){
            int l=n,r=1;
            for(int i=1;i<=n;i++){
                if(x[n]-x[i]<=d&&x[i]-x[0]<=d){
                    l=min(l,i);
                    r=max(r,i);
                }
            }
            long long ans=0;
            for(int i=1;i<=n;i++){
                if(r-l>2){
                    continue;
                }
                if(i<l){
                    int k=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
                    if(k>=n){
                        continue;
                    }
                    int k2=upper_bound(x+1,x+1+n,x[k-1]+d)-x-1;
                    int k3=upper_bound(x+1,x+1+n,x[k-2]+d)-x-1;
                    ans+=k2-k3;
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            int last=i;
            int ll=0;
            int suc=0;
            x[i-1]=x[i]-2e18-1;
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[last]>d){
                    ll=last;
                    last=j-1;
                    if(x[last]-x[ll-1]<=d){
                        if(suc==1){
                            break;
                        }
                        if(x[last]-x[ll-2]<=d){
                            break;
                        }
                        suc=1;
                    }
                }
                if(ll==last||x[j]-x[j-1]>d){
                    break;
                }
                //cout<<i<<' '<<j<<' '<<last<<' '<<ll<<' '<<suc<<'\n';
                if(ll==0){
                    continue;
                }
                if(x[j]-x[last-1]<=d){
                    if(x[j]-x[last-2]<=d){
                        continue;
                    }
                    if(suc){
                        continue;
                    }
                    //cout<<i<<' '<<j<<'\n';
                    ans++;
                }
                else{
                    if(suc){
                        //cout<<' '<<i<<' '<<j<<'\n';
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//Arsenal was and still is my love.
//North London Forever.
