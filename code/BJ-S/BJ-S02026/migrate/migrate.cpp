#include <bits/stdc++.h>
using namespace std;
int c,t;//试图不用离散化
long long n,d;
long long x[2000010];
long long zy[2000010];//最远距可达点
long long dzy[2000010];//反着的最远可达点
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){
        memset(zy,0,sizeof(zy));
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            int l=i,r=n,mid;
            while(l<=r){
                mid=(l+r)/2;
                if(x[mid]-x[i]>d)r=mid-1;
                if(x[mid]-x[i]==d){
                    zy[i]=mid;
                    break;
                }
                if(x[mid]-x[i]<d){
                    zy[i]=mid;
                    l=mid-1;
                }
            }
        }
        for(int i=n;i>=1;i--){
            int l=1,r=i,mid;
            while(l<=r){
                mid=(l+r)/2;
                if(x[i]-x[mid]>d)l=mid+1;
                if(x[i]-x[mid]==d){
                    dzy[i]=mid;
                    break;
                }
                if(x[i]-x[mid]<d){
                    dzy[i]=mid;
                    r=mid-1;
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n-3;i++){
            if(dzy[zy[zy[i]-1]]==zy[i]-1){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
