#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
bool f=1;
int a[N];
int anweiyu;
int maxa=-1;
int maxn=-1;
int maxb=-1;
int maxc=-1;
bool cmp(int x,int y){
    return x>y;
}
void dfs(int x,int cnt,int ans){
    if(x>n){
        if(cnt==m)maxn=max(maxn,ans);
        return ;
    }
    dfs(x+1,cnt,ans);
    if(cnt<m){
        if(ans==-1){
            ans=a[x];
        }else{
            ans=(ans&a[x]);
        }
        dfs(x+1,cnt+1,ans);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int suiji;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)anweiyu=a[i];
        anweiyu=(anweiyu&a[i]);
        maxa=max(maxa,a[i]);
        int sum=1;
        bool flag=1;
        for(int i=1;i<=20;i++){
            if(a[i]==0){
                flag=0;
                break;
            }
            sum*=2;
            if(sum-1==a[i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            f=0;
        }
    }
    if(n<=20){
        dfs(0,0,-1);
        cout<<maxn;
    }else if(m==1){
        cout<<maxa;
    }else if(m==n){
        cout<<anweiyu;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                int anwei=(a[i]&a[j]);
                maxb=max(maxb,anwei);
            }
        }
        cout<<maxb;
    }else if(m==n-1){
        for(int i=1;i<=n;i++){
            int anwei=-1;
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                if(anwei==-1)anwei=a[j];
                anwei=(anwei&a[j]);
            }
            maxc=max(maxc,anwei);
        }
        cout<<maxc;
    }else if(f==1){
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
    }else{
        cout<<0;
    }
    return 0;
}
