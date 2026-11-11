#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
#define int long long
int n,d;
int a[2000001],b[2000001],nextt[2000001],last[2000001];
int t[1001][1001],mp[1001][1001];
int mink=100,cc=0;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(t[i][k]+t[k][j]<t[i][j]){
                    mp[i][j]=0;
                    t[i][j]=t[i][k]+t[k][j];

                }else if(t[i][k]+t[k][j]==t[i][j]){
                    mp[i][j]++;
                }
            }
        }
    }
}
int ccc(int s,int to,int now,int k){
    //cout<<now<<endl;
    if(k>mink) return 1;
    if(now==to){
        //cout<<s<<" "<<to<<" "<<k<<endl;
        if(cc>2) return 0;
        cc++;
        mink=k;
    }
    for(int i=nextt[now];i>now;i--){
        if(!ccc(s,to,i,k+1)){
            return 0;
        }
    }
    return 1;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,q;
    cin>>c>>q;
    while(q--){

        memset(mp,0,sizeof(mp));
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                t[i][j]=1e18+1;
            }
        }
        int len=1;
        for(int i=1;i<=n-1;i++){
            while(a[len]-a[i]<=d&&len<=n){
                len++;
            }
            len--;
            nextt[i]=len;
            //cout<<i<<" "<<nextt[i]<<endl;
            if(last[len]==0) last[len]=i;
        }
        int ans=0;
        if(n<=3){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    int k=i;
                    cc=0;
                    mink=1e9+1;
                    if(!ccc(i,j,i,0)){
                        //cout<<i<<" "<<j<<endl;
                        continue;
                    }
                    //cout<<i<<" "<<j<<" "<<cc<<endl;
                    if(cc==2){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=last[i];j<=nextt[i];j++){
                t[i][j]=1;
            }
        }
        floyd();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(mp[i][j]==1) ans++;
                //cout<<mp[i][j]<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
