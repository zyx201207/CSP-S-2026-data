#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k,a[N];
vector<int> d[N];
int f(){
    int ans=3,w=0;
    if(k==2)return 1;
    for(int i=1;i<=n;i++){
        if(d[i].size()+1>=k){
            return 2;
        }
        if(d[i].size()>d[w].size())w=i;
    }
    a[1]=w;
    int s=d[w].size();
    int b=k-s-1,m=0,cnt=1;
    while(b>0){
        for(int i=1;i<=cnt;i++){
            if(i==1&&cnt-1>d[w].size())continue;
            s=d[a[i]].size();m=0;
            for(int j=0;j<s;j++){
                int o=d[a[i]][j];
                if(d[o].size()>b)return ans;
                if(d[o].size()>d[m].size())m=o;
            }
            ans++;
            a[++cnt]=m;
            b-=d[m].size();
        }
    }
    return ans;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=N;i++)a[i]=i;
        for(int i=1;i<=n;i++)d[i].clear();
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
                int u,v;
            scanf("%d%d",&u,&v);
            d[u].push_back(v);
            d[v].push_back(u);
        }
        printf("%d\n",f());
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
