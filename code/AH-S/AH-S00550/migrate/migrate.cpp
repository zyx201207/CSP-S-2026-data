#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,a[2000005],L[2000005],R[2000005],f[2000005],v[2000005];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c==13||c==14){
            for(int i=1;i<=n;i++){
                int l=1,r=i;
                while(l<r){
                    int mid=l+r>>1;
                    if(a[i]-a[mid]<=d)r=mid;
                    else l=mid+1;
                }
                L[i]=l;
                l=i,r=n;
                while(l<r){
                    int mid=l+r+1>>1;
                    if(a[mid]-a[i]<=d)l=mid;
                    else r=mid-1;
                }
                R[i]=l;
                v[R[i]-1]++;
            }int ans=0;
            for(int i=1;i<=n;i++)ans+=v[L[i]];
            cout<<ans<<"\n";
            continue;
        }
        if(c==11||c==12){
            if(a[3]-a[1]>d){
                cout<<0<<"\n";
                continue;
            }
            if(a[n]-a[1]<=d){
                cout<<0<<"\n";
                continue;
            }
            for(int i=0;i<=n;i++){
                if(a[i+1]-a[1]>d){
                    cout<<max(0ll,n-(2*i-2)+1)<<"\n";
                    break;
                }
            }
            continue;
        }
        for(int i=1;i<=n;i++){
            int l=1,r=i;
            while(l<r){
                int mid=l+r>>1;
                if(a[i]-a[mid]<=d)r=mid;
                else l=mid+1;
            }
            L[i]=l;
            l=i,r=n;
            while(l<r){
                int mid=l+r+1>>1;
                if(a[mid]-a[i]<=d)l=mid;
                else r=mid-1;
            }
            R[i]=l;
        }
        if(n>400){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)v[j]=1e18,f[j]=0;
                v[i]=0;f[i]=1;
                for(int j=i;j<=n;j++){
                    for(int k=max(R[j]-4,j+1);k<=R[j];k++){
                        if(v[k]>v[j]+1){
                            v[k]=v[j]+1;
                            f[k]=f[j];
                        }else if(v[k]==v[j]+1)f[k]+=f[j];
                    }
                }
                for(int j=1;j<=n;j++)if(f[j]==2)ans++;
            }
            cout<<ans<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)v[j]=1e18,f[j]=0;
            v[i]=0;f[i]=1;
            for(int j=i;j<=n;j++){
                for(int k=j+1;k<=R[j];k++){
                    if(v[k]>v[j]+1){
                        v[k]=v[j]+1;
                        f[k]=f[j];
                    }else if(v[k]==v[j]+1)f[k]+=f[j];
                }
            }
            for(int j=1;j<=n;j++)if(f[j]==2)ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
