#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,p,cnt;
int a[N],e[N],t[N],u[N],v[N],w[N],dis[N];
void get(){
    for(int i=1;i<=m;i++){
        bool flag=0;
        for(int j=1;j<=cnt*2;j++)
            if(dis[v[j]]>dis[u[j]]+w[j])
                dis[v[j]]=dis[u[j]]+w[j],flag=1;
        if(!flag)
            break;
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
        scanf("%d",&e[i]);
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
            cin>>a[j]>>t[j];
        for(int j=1;j<k;j++)
            for(int s=j+1;s<=k;s++)
                u[++cnt]=a[j],v[cnt]=a[s],w[cnt]=t[j]+t[s];
    }
    for(int i=1;i<=cnt;i++)
        u[i+cnt]=v[i],v[i+cnt]=u[i],w[i+cnt]=w[i];
    while(p--){
        int st,ed;
        cin>>st>>ed;
        memset(dis,0x3f,sizeof(dis));
        dis[st]=0;
        get();
        cout<<e[st]+dis[ed]+e[ed]<<" ";
    }
    return 0;
}
