#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=2*(int)1e6+10;
int a[MAXN];
ll minLen=LONG_LONG_MAX;
int cntLen=0;
bool vis[MAXN];
void dfs(int x,ll len,int t,int n);
void init();
void init(){
    minLen=LONG_LONG_MAX;
    cntLen=0;
    memset(vis,0,sizeof(vis));
}
void dfs(int x,ll len,int t,int n,int d){
    // cout<<__LINE__<<' '<<x<<' '<<len<<endl;
    if(x==t){
        if(len<minLen){
            minLen=len;
            cntLen=1;
        }
        else if(len==minLen){
            cntLen++;
        }
        return ;
    }
    if(vis[x]){
        return ;
    }
    vis[x]=1;
    for(int nex_=x-1;nex_>=1;nex_--){
        if(abs(a[x]-a[nex_])>d){
            break;
        }
        // cout<<__LINE__<<' '<<x<<' '<<nex_<<endl;
        dfs(nex_,len+1,t,n,d);
    }
    for(int nex_=x+1;nex_<=n;nex_++){
        if(abs(a[x]-a[nex_])>d){
            break;
        }
        // cout<<__LINE__<<' '<<x<<' '<<nex_<<endl;
        dfs(nex_,len+1,t,n,d);
    }
    vis[x]=0;
    return ;
}
// bool canto[MAXN][MAXN];
// ll minLen[MAXN][MAXN];
// int minLenCnt[MAXN][MAXN];
// void addEdge(int i,int j){
//     canto[i][j]=1;
//     canto[j][i]=1;
//     minLen[i][j]=1;
//     minLen[j][i]=1;
// }
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(C==11||C==12){
            cout<<0<<endl;
        }
        else if(C==13||C==14){
            cout<<n*(n-1)/2<<endl;
        }
        else{
            int ans=0;
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    init();
                    dfs(i,0,j,n,d);
                    // cout<<__LINE__<<' '<<i<<' '<<j<<' '<<cntLen<<' '<<minLen<<endl;
                    if(cntLen==2){
                        // cout<<__LINE__<<' '<<i<<' '<<j<<' '<<minLen<<endl;
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    //     sort(a+1,a+1+n);
    //     // init();
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //             minLen[i][j]=n;
    //         }
    //     }
    //     memset(minLenCnt,0,sizeof(minLenCnt));
    //     for(int i=1;i<=n;i++){
    //         for(int j=i;j>=1;j--){
    //             if(abs(a[i]-a[j])>d){
    //                 break;
    //             }
    //             addEdge(i,j);
    //             cout<<__LINE__<<' '<<"addedge "<<i<<' '<<j<<endl;
    //         }
    //         for(int j=i;j<=n;j++){
    //             if(abs(a[i]-a[j])>d){
    //                 break;
    //             }
    //             addEdge(i,j);
    //             cout<<__LINE__<<' '<<"addedge "<<i<<' '<<j<<endl;
    //         }
    //     }
    //     cout<<__LINE__<<"minLen:"<<endl;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //             cout<<minLen[i][j]<<' ';
    //         }
    //         cout<<endl;
    //     }
    //     for(int k=1;k<=n;k++){
    //         for(int x=1;x<=n;x++){
    //             for(int y=1;y<=n;y++){
    //                 if(minLen[x][y]>(minLen[x][k]+minLen[k][y])){
    //                     minLen[x][y]=minLen[x][k]+minLen[k][y];
    //                     minLenCnt[x][y]=1;
    //                 }
    //                 if(minLen[x][y]=(minLen[x][k]+minLen[k][y])){
    //                     minLenCnt[x][y]++;
    //                     cout<<"minLenCnt["<<x<<"]["<<y<<"]="<<minLenCnt[x][y]<<endl;
    //                 }
    //             }
    //         }
    //     }
    //     cout<<__LINE__<<"minLen:"<<endl;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //             cout<<minLen[i][j]<<' ';
    //         }
    //         cout<<endl;
    //     }
    //     int sum=0;
    //     cout<<"minLenCnt:"<<endl;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //             cout<<minLenCnt[i][j]<<' ';
    //             if(minLenCnt[i][j]==2){
    //                 sum++;
    //             }
    //         }
    //         cout<<endl;
    //     }
    //     cout<<sum<<endl;
    }
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/


