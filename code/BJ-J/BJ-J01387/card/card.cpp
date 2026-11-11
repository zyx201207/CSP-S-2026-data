#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[500005],sum[500005];
bool vis[500005];
int n,m;
void solve2(){
    int cnt1=0,cnt2=0;
    for(int g=1;g<=n;g++){
        if(sum[n]-sum[g-1]!=(n-g+1)&&sum[n]-sum[g-1]!=(n-g+1)*2){
            cnt1++;
            cnt2++;
        }
        else if(sum[n]-sum[g-1]==(n-g+1)&&sum[n]-sum[g-1]!=(n-g+1)*2){
            cnt2++;
        }
        else if(sum[n]-sum[g-1]!=(n-g+1)&&sum[n]-sum[g-1]==(n-g+1)*2){
            cnt1++;
        }
    }
    cout<<cnt1<<' '<<cnt2;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    if(m==2){
        solve2();
        return 0;
    }
    for(int g=1;g<=n;g++){
        memset(vis,0,sizeof vis);
        vector<int> cd;
        for(int i=g;i<=n;i++){
            if(vis[a[i]]){
                while(cd.back()!=a[i]){
                    vis[cd.back()]=0;
                    cd.pop_back();
                }
                cd.pop_back();
            }
            cd.push_back(a[i]);
            vis[a[i]]=1;
        }
        for(auto v:cd){
            cnt[v]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
