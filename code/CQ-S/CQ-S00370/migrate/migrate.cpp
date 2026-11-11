#include<bits/stdc++.h>
using namespace std;
long long n,d,a[1000005],mind[1000005],cnt[1000005];
//long live ccf.
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        long long ans=0;
        for(int i=1;i<=n;i++){
            memset(mind,0x3f,sizeof mind);
            memset(cnt,0,sizeof cnt);
            mind[i]=0;cnt[i]=1;
            for(int j=i;j>=1;j--){
                if(cnt[j]==2)ans++;
                for(int k=j;k>=1&&a[j]-a[k]<=d;k--){
                    if(mind[j]+1==mind[k])cnt[k]+=cnt[j];
                    else if(mind[j]+1<mind[k]){
                        mind[k]=mind[j]+1;
                        cnt[k]=cnt[j];
                    }
                }
            }
            for(int j=i;j<=n;j++){
                if(cnt[j]==2)ans++;
                for(int k=j;k<=n&&a[k]-a[j]<=d;k++){
                    if(mind[j]+1==mind[k])cnt[k]+=cnt[j];
                    else if(mind[j]+1<mind[k]){
                        mind[k]=mind[j]+1;
                        cnt[k]=cnt[j];
                    }
                }
            }
        }
        cout<<ans/2<<'\n';
    }
    return 0;
}
//重生之我肘飞三百个保安并 ak NOIP。