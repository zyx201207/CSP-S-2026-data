#include<iostream>
using namespace std;
const int N=2e5+11,LOG=32;
int n,m,a[N],ans,t[N][LOG],id[N],maxn=0;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        id[i]=1;
        cin>>a[i];
        int tmp=a[i],cnt=0;
        while(tmp!=0){
            t[i][cnt]=tmp%2;
            tmp/=2,cnt++;
        }
        maxn=max(maxn,cnt-1);
    }
    for(int j=maxn;j>=0;j--){
        int f=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(id[i]==0)continue;
            if(t[i][j]==1){
                cnt++;
            }
        }
        if(cnt<m)continue;
        ans+=(1<<j);
        for(int i=1;i<=n;i++){
            if(t[i][j]==0)id[i]=0;
        }
    }
    cout<<ans;
    return 0;
}
//OK
