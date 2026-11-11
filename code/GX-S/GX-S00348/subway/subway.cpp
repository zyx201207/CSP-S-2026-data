#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,tmp,t1,k[505],a[505][500005],t[505][500005],w[500005],x[100005],y[100005];//That is interesting,the variable 'c' is the number of test point,need read!
bool v[500005];
vector<vector<int> >mp;//this is a map
void dfs(int now,int endd,int t){
    if(now==endd){
        ans=t;
        return;
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<k[j];k++){
            if(a[j][k]==now){
                t1=t[j][k];
                break;
            }
        }
    }
    for(int i=0;i<k[t1];i++){
        if(!v[a[t1][i]){
            v[a[t1][i]]=true;
            dfs(a[t1][i],endd,t+t[t1][i]);
            v[a[t1][i]]=false;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);//<-It also to save time
    for(int i=0;i<m;i++)scanf("%d",&w[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&k[i]);
        for(int j=0;j<k[i];j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
            mp[i].push_back(a[i][j]);//build map
        }
    }
    for(int i=0;i<q;ans=0,i++){
        scanf("%d%d",&x[i],&y[i]);
        for(int j=0;j<n;j++){
            for(int k=0;k<k[j];k++){
                if(a[j][k]==x[i]){
                    tmp=t[j][k];
                    break;
                }
            }
        }
        dfs(x[i],y[i],w[x[i]]+t[j][k]);
        printf("%d",ans);
    }
    return 0;
}
