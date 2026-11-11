#include<bits/stdc++.h>
using namespace std;
long long n,c,t,k;
long long side[20][20],x[20],f[20],minn=30,floyd[20][20];
int find1(int f1){
    if(f[f1]==f1) return f1;
    else return f[f1]=(find1(f[f1]));
}
void DFS(int lay){
    if(lay==n) {
        int flag1=0;
        for(int i=1;i<=n;i++) if(x[i]) flag1++;
        if(flag1!=k) return;
        for(int i=1;i<=n;i++) f[i]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(side[i][j]&&x[i]&&x[j]){
                    int x2=find1(i),x3=find1(j);
                    if(x2!=x3){
                        f[x3]=x2;
                    }
                }
            }
        }
        long long flag=0;
        for(int i=1;i<=n;i++) if(f[i]==i&&x[i]) flag++;
        if(flag>2) return;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {if(side[i][j]==1) floyd[i][j]=1;else floyd[i][j]=0x3fffffff;}
        for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {if(k==i||i==j||j==k) continue;floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);}
        long long maxn=0,minn1=0;
        for(int i=1;i<=n;i++){
            if(!x[i]) minn1=30;
            for(int j=1;j<=n;j++){
                if(i!=j&&!x[i]&&x[j]) minn1=min(minn1,floyd[i][j]);
            }
            if(!x[i]) maxn=max(maxn,minn1);
        }
        minn=min(minn,maxn);
        }
    else{
        x[lay+1]=0;
        DFS(lay+1);
        x[lay+1]=1;
        DFS(lay+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
            minn=30;
        cin>>n>>k;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) side[i][j]=0;
        for(int i=1;i<n;i++) {
            int a,b;
            cin>>a>>b;
            side[a][b]=1;
            side[b][a]=1;
        }
        DFS(0);
        cout<<minn<<endl;
    }
    return 0;
}
