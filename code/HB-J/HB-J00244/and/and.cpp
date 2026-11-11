#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],sum,maxn=-1000,maxm=-1000,p[200005],vis[200005],maxans=-100;
ll maxnm,sumnm;
void dfs(int step,int lst){
    if(step==m){
        ll sumn=p[1]&p[2];
 //       cout<<p[1]<<" "<<p[2]<<" ";
        for(int i=3;i<=m;i++){
            sumn=sumn&p[i];
 //           cout<<p[i]<<" ";
        }
 //       cout<<endl;
        maxans=max(maxans,sumn);
    }
    for(int i=lst+1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            p[step+1]=a[i];
            dfs(step+1,i);
            vis[i]=0;
        }
    }
}
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sum=a[1]&a[2];
    for(int i=3;i<=n;i++){
        sum=a[i]&sum;
    }
    if(n==m){
        cout<<sum;
        return 0;
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                maxm=max(maxm,a[i]&a[j]);
            }
        }
        cout<<maxm;
        return 0;
    }
    if(n<=25){
        dfs(0,0);
        cout<<maxans;
        return 0;
    }
    if(m==(n-1)){
        for(int i=1;i<=n;i++){
            if(i==1){
                sumnm=a[2]&a[3];
                for(int j=4;j<=n;j++){
                    sumnm=a[j]&sumnm;

                }
                maxnm=max(maxnm,sumnm);
            }
            else if(i==2){
                sumnm=a[1]&a[3];
                for(int j=4;j<=n;j++){
                    sumnm=a[j]&sumnm;

                }
                maxnm=max(maxnm,sumnm);
            }
            sumnm=a[1]&a[2];
            for(int j=3;j<i;j++){
                sumnm=sumnm&a[j];
            }
            for(int j=i+1;j<=n;j++){
                sumnm=sumnm&a[j];
            }
            maxnm=max(maxnm,sumnm);
        }
    }
    sort(a+1,a+1+n,cmp);
    cout<<a[m];
    return 0;
}
