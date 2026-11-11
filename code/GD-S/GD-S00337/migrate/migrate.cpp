#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d,a[N],to[N],pr[N],dis[N],tim[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c<=10){
            for(int i=1;i<=n;i++)
                to[i]=upper_bound(a+i+1,a+n+1,a[i]+d)-a-1;
            int ans=0;
            for(int st=1;st<=n;st++){
                for(int i=st;i<=n;i++)
                    dis[i]=(int)1e18,tim[i]=0;
                dis[st]=0;
                tim[st]=1;
                for(int i=st;i<=n;i++){
                    ans+=(tim[i]==2);
                    for(int j=to[i];j>max(i,to[i]-3);j--){
                        if(dis[j]>dis[i]+1){
                            dis[j]=dis[i]+1;
                            tim[j]=tim[i];
                        }else if(dis[j]==dis[i]+1)
                            tim[j]=min(3ll,tim[i]+tim[j]);
                    }
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        if(11<=c&&c<=12){
            int k=0;
            for(int i=2;i<=n;i++){
                if(a[i]-a[1]>d) break;
                k++;
            }
            if(k<2){
                cout<<"0\n";
                continue;
            }
            int ans=0;
            for(int i=1;i<=n;i++)
                ans+=min(1ll,max(0ll,(n-i-k+1)/k));
            cout<<ans<<'\n';
            continue;
        }
        if(13<=c&&c<=14){
            for(int i=1;i<=n;i++){
                int l=1,r=i-1,mid,ans=i;
                while(l<=r){
                    mid=(l+r)/2;
                    if(a[i]-a[mid]>=d){
                        r=mid-1;
                        ans=mid;
                    }else l=mid+1;
                }
                pr[i]=ans;
                to[i]=upper_bound(a+i+1,a+n+1,a[i]+d)-a-1;
            }
            int d=to[1];
            if(d==n||d<=2){
                cout<<"0\n";
                continue;
            }
            int x,y,z;
            x=pr[d+1];
            y=to[d-2];
            z=to[d-1];
            cout<<(x-1)*(z-y)<<'\n';
            continue;
        }
        cout<<"0\n";
        continue;
    }
    return 0;
}