#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],lst[500010],id[500010];
int ans[500010];
int pre[500010];
bool flag[500010];
int c[5010];
int lowbit(int x){
    return (x&-x);
}
void add(int x,int y){
    while(x<=n){
        c[x]+=y;
        x+=lowbit(x);
    }
}
int qry(int x){
    int ret=0;
    while(x){
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}
bool check(){
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]) return false;
    }
    return true;
}
int cnt[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    if(check()){
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
        }
        int sum=0;
        for(int i=1;i<=m;i++){
            sum+=cnt[i];
            cout<<sum<<" ";
        }
        return 0;
    }

    if(n<=5000){
        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++) lst[j]=0;
            for(int j=1;j<=n;j++) c[j]=pre[j]=0;

            for(int j=i;j<=n;j++){
                int p=lst[a[j]];
                while(p&&qry(p)) p=pre[p];
                pre[j]=p;
                if(p){
                    add(p,1);
                    add(j,-1);
                }

                lst[a[j]]=j;
            }

            for(int j=1;j<=m;j++) lst[j]=0;
            for(int j=i;j<=n;j++){
                if(!qry(j)) lst[a[j]]=1;
            }
            for(int j=1;j<=m;j++){
                if(lst[j]) ans[j]++;
            }

        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
        return 0;
    }
    return 0;
}
