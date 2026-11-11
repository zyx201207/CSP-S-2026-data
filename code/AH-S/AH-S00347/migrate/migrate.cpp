#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,T,n;
long long a[2000005],d,w1[2000005],w2[2000005];
int f1[2000005][22],f2[2000005][22],s1[2000005][22],s2[2000005][22];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=2;i<=n;i++){
            if((a[i]-a[i-1])==a[2]-a[1]) cnt++;
        }
        if(cnt==n-1){
            if(a[2]-a[1]>=d) cout<<0<<'\n';
            else{
                cout<<max(n-d/(a[2]-a[1])*2+1,0LL)<<'\n';
            }
            continue;
        }
        for(int i=1;i<=n;i++){
            int l=0,r=i;
            while(l+1<r){
                int mid=(l+r)/2;
                if(a[i]-a[mid]<=d) r=mid;
                else l=mid;
            }
            f1[i][0]=r;
            l=i,r=n+1;
            while(l+1<r){
                int mid=(l+r)/2;
                if(a[mid]-a[i]<=d) l=mid;
                else r=mid;
            }
            f2[i][0]=l;
        }
        for(int i=1;i<n;i++) s1[i][0]=f1[i+1][0]-f1[i][0];
        for(int i=2;i<=n;i++) s2[i][0]=f2[i][0]-f2[i-1][0];
        for(int i=1;i<=21;i++){
            for(int j=1;j<=n;j++){
                f1[j][i]=f1[f1[j][i-1]][i-1];
                f2[j][i]=f2[f2[j][i-1]][i-1];
                if(s1[j][i-1]==0) s1[j][i]=0;
                else s1[j][i]=s1[j][i-1]+s1[f1[j][i-1]][i-1];
                if(s2[j][i-1]==0) s2[j][i]=0;
                else s2[j][i]=s2[j][i-1]+s2[f2[j][i-1]][i-1];
            }
        }
        for(int i=1;i<=n;i++){
            int x=i;
            w1[i]=w2[i]=0;
            for(int j=21;j>=0;j--){
                if(s1[x][j]){
                    w1[i]+=s1[x][j];
                    x=f1[x][j];
                }
            }
            x=i;
            for(int j=21;j>=0;j--){
                if(s2[x][j]){
                    w2[i]+=s2[x][j];
                    x=f2[x][j];
                }
            }
        }
        long long ans=0;
        for(int i=2;i<n-1;i++){
            int l=f1[i+1][0],r=f2[i][0];
            if(a[i+2]-a[l]<=d||l>=i) continue;
            if(a[r]-a[i-1]<=d||r<=i+1) continue;
            ans+=(w1[l]+f1[i+2][0]-f1[i+1][0])*(w2[r]+f2[i][0]-f2[i-1][0]);
        }
   //     cout<<n<<' '<<a[2]-a[1]<<' '<<d<<'\n';
        cout<<ans<<'\n';
    }
    return 0;
}
