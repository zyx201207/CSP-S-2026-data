#include<bits/stdc++.h>
using namespace std;
long long c,T,n,h,x[2000005];
bool f[15];
map<int,int> t;
int dfs(int limi,int v,int limj,int cnt){
    if(v>limj){
        long long l=x[limi],hh=0;
        for(int i=limi+1;i<=limj;i++){
            if(f[i]){
                hh++;
                if(l+h<x[i]){
                    return 0;
                }
                l=x[i];
            }
        }
        //cout<<hh<<" "<<cnt<<"\n";
        if(hh!=cnt) return 0;
        else return 1;
    }
    int summ=0;
    if(v!=limi&&v!=limj){
        f[v]=false;
        summ+=dfs(limi,v+1,limj,cnt);
    }
    f[v]=true;
    summ+=dfs(limi,v+1,limj,cnt);

    return summ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        int ans=0;
        cin>>n>>h;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            t[x[i]]++;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                long long l=0,cnt=0,now=i;
                while(true){
                    cnt++;
                    for(int k=now+1;k<=j;k++){
                        if(x[k]-x[now]<=h) l=k;
                        else break;
                    }
                    if(now==l){
                        cnt=0x3f3f3f3f;
                        break;
                    }
                    now=l;
                    if(l>=j) break;
                }
                //cout<<i<<" "<<j<<" "<<dfs(i,i,j,cnt)<<" "<<cnt<<"\n";
                if(dfs(i,i,j,cnt)==2) ans++;
                memset(f,0,sizeof(f));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
