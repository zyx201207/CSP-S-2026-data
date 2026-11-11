#include<bits/stdc++.h>
using namespace std;
vector<int>points[2000005];
int c,t,n;
long long d,x[2000005],h[2000005],num[2000005],sum=0,mmin=1e18+5;
void init(){
    sum=0;
    for(int i=1;i<=n;i++){
        while(!points[i].size()==0) points[i].pop_back();
        h[i]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(max(x[i]-x[j],x[j]-x[i])<=d){
                points[i].push_back(j);
            }
        }
    }
    return;
}
void dfs(int p,int fa,long long he){
    if(h[p]==-1) {
        h[p]=he;
        num[p]=1;
    }
    else{
        if(h[p]==he){
            num[p]++;
        }
        else if(h[p]>he){
            h[p]=he;
            num[p]=1;
        }
    }
    for(int i=0;i<points[p].size();i++){
        if(points[p][i]!=fa && (h[points[p][i]]==-1 || h[points[p][i]]>=he+1)){//
            dfs(points[p][i],p,he+1);//?
        }
    }
    return;
}
void count(){
    for(int i=1;i<=n;i++){
        if(h[i]!=-1 && num[i]==2) sum++;
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        mmin=1e18+5;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            if(i>1) mmin=min(mmin,x[i]-x[i-1]);
        }
        if(mmin>d){
            printf("0\n");
            continue;
        }
        if(n<=5000){
            init();
            for(int i=1;i<=n;i++){
                for(int i=1;i<=n;i++){
                    h[i]=-1;
                    num[i]=0;
                }
                dfs(i,0,0);
                count();
            }
        }
        else{
            sum=n*(n-1)/2;
        }
        printf("%lld\n",sum/2);//
    }
    return 0;
}