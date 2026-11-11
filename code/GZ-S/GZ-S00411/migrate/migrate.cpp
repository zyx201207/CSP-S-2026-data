//GZ-S00411 jiangshiyu 蒋世宇
#include <bits/stdc++.h>
using namespace std;
int c,t;
int n[100005];
long long d[100005];
long long x[100005][2000005];
int h[100005][100005];
int ans[100005]={0};
long long tmp[100005][100005];
int mind = 2000005;
long long prin[100005][100005];



int now[100005]={0};
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    for(int i=1;i<=t;i++){
       cin >>n>>d;
       for(int i=1;i<=n;i++) cin>>x[t][i];
    }
     for(int j=1;j<=t;j++){
      for(int i=1;i<=n;i++){
            int p=1,q=i+1;
       while(q>p){
        if(x[t][q]-x[t][p]>d[t]) continue;
        if(x[t][q]-x[t][p]<=d[t]){
          tmp[p][q] += 1;
          p+=d[t];
          break;
        };

      }
     if(tmp[p][q]<=mind)
        mind=tmp[p][q];

     }
    }
    for(int i=1;i<=n;i++)
        for(int j=n;j>=i;j--)
           if(tmp[i][j]==mind) prin[i][j] ++;

    for(int i=1;i<=n;i++)
        for(int j=n;j>=1;j--)
           if(prin[i][j]==2) ans[t] ++;

    for(int i=1;i<=n;i++)
        for(int j=n;j>=i;j--) tmp[i][j]=0;
    for(int i=1;i<=t;i++) cout<<ans[i]<<" ";
    return 0;

}
