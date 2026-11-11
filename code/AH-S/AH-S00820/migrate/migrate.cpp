#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,T;
    cin>>c>>T;
    while(T--){
        ll n,d;
        cin>>n>>d;
        vector<int>fs(n);
        for(auto &x:fs) cin>>x;
        vector<vector<ll>> pdb(n,vector<ll>(n,LLONG_MAX)),lk(n,vector<ll>(n));
        int cnt=0;
        for(int len=1;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                if(len==1){
                    pdb[i][i]=0;
                    lk[i][i]=1;
                    continue;
                }
                int j=i+len-1;
                if(len!=2)
                for(int k=i;k<j;k++){
                    for(int t=k+1;t<=j;t++){
                        if(pdb[i][k]!=LLONG_MAX && pdb[t][j]!=LLONG_MAX && fs[t]-fs[k]<=d){
                            ll nn=pdb[i][k]+pdb[t][j]+1;
                            ll nx=lk[i][k]*lk[t][j];
                            if(nn<pdb[i][j]) pdb[i][j]=nn,lk[i][j]=nx;
                            else if(nn==pdb[i][j]) lk[i][j]+=nx;
                        }
                        if(fs[t]-fs[k]>d) break;
                    }
                }
                if(lk[i][j]==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
//pdboynbkls
