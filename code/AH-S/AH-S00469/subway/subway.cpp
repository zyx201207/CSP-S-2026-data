#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5,MAXN_=1e5+5,maxn=1e9;
int c,n,m,d,q;
int w_[MAXN];
int k[505];
int a[MAXN],t[MAXN];
int sub[1000][1000]={maxn};
bool f[1000][1000]={false};
int w[MAXN];
int flag[MAXN];
bool eff[MAXN];
struct travel{
    int x_,y_;
};
travel tr;
bool if_effective(int x){
    return eff[x];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w_[i];
        w[i]+=w_[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j]>>t[j];
            w[a[j]]+=t[j];
            flag[a[j]]++;
        }
        for(int j=1;j<k[i];j++){
            for(int l=j+1;l<=k[i];l++){
                f[a[j]][a[l]]=f[a[l]][a[j]]=true;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(flag[i]>1){
            w[i]-=w_[i];
            eff[i]=true;
        }
    }
    while(q--){
        cin>>tr.x_>>tr.y_;
        eff[tr.x_]=eff[tr.y_]=true;
        long long ans=w[tr.x_];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i!=j&&f[i][j]){
                    if(if_effective(j)){
                        sub[i][j]=w[j];
                    }else{
                        sub[i][j]=0;
                    }
                    if(if_effective(i)){
                        sub[j][i]=w[i];
                    }else{
                        sub[j][i]=0;
                    }
                }
            }
        }
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    if(sub[i][k]+sub[k][j]<=sub[i][j]){
                        sub[i][j]=sub[i][k]+sub[k][j];
                    }
                }
            }
        }
        ans+=sub[tr.x_][tr.y_];
        cout<<ans<<endl;
        eff[tr.x_]=eff[tr.y_]=false;
    }
    return 0;
}