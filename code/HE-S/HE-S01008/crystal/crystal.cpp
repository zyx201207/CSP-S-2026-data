#include<bits/stdc++.h>
#define MAXN 5005
using namespace std;
int a[MAXN],d[MAXN][MAXN],ans,n,m;

int dfs(int m){
    int a=1;
    for(int i=0;i<n;i++){
        int cnt=0,sum=0;
        for(int j=i;j<n;j++){
            sum+=d[j][i];
            if(sum<=m)cnt++;
        }
        a=max(a,cnt);
    }
    return a;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n-1);
    for(int i=1;i<n;i++){
        int tmp[MAXN];
        memset(tmp,0X3F3F3F3F,sizeof tmp);
        for(int j=0;j<i;j++){
            tmp[i]=a[i]-a[j];
            sort(tmp,tmp+i-1);
            d[i][j]=tmp[j];
        }
    }
    
    ans = dfs(m);
    cout<<ans;
    return 0;
}
