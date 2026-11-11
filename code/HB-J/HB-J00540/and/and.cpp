#include<bits/stdc++.h>
using namespace std;
int n,m,x,t,cnt,f[200005][35],u[200005],ans[35];long long anss,k=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;t=31;
        while(t--)f[i][t]=x%2,x/=2;
        u[i]=1;
    }for(int i=0;i<=30;i++){
        cnt=0;
        for(int j=0;j<n;j++)if(f[j][i]&&u[j])cnt++;
        if(cnt>=m)for(int j=0;j<n;j++)if(!f[j][i])u[j]=0;
    }for(int i=0;i<=30;i++)ans[i]=1;
    for(int i=0;i<n;i++)if(u[i])for(int j=0;j<=30;j++)if(ans[j]&&!f[i][j])ans[j]=0;
    for(int i=30;i>=0;i--){if(ans[i])anss+=k;k*=2;}
    cout<<anss;
    return 0;
}
