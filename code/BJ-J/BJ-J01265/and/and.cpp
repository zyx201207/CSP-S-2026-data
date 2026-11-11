#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],ans,maxsum=-1;
bool f[200005];
void dfs(int step,int cnt,int wei){
    if(step==m&&wei<=n){
        maxsum=max(maxsum,cnt);
        return;
    }
    if(wei>n)return;
    for(int i=wei+1;i<=n;i++){
        if(cnt&a[i]<cnt/32)continue;
        else dfs(step+1,cnt&a[i],i);
    }
}
int main (){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >>a[i];
    if(m==1){
        int maxn=-1;
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
        return cout << maxn,0;
    }
    else if(m==n){
        int cnt;
        for(int i=1;i<=n;i++){
            if(i==1)cnt=a[i];
            else cnt=cnt&a[i];
        }
        return cout << cnt,0;
    }
    else if(m==2){
        int maxn=-1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)maxn=max(maxn,a[i]&a[j]);
        return cout << maxn,0;
    }
    dfs(0,0,1);
    cout << maxsum;
    return 0;
}