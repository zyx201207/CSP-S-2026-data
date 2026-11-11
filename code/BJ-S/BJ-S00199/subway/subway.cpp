#include<bits/stdc++.h>
using namespace std;
//mt19937 rng(random_device{}());
const int N=505,M=5e5+5;
int c,n,m,d,q,k[N],w[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    vector<int> e[n+5],a[m+5],v[m+5];
    int d[n+5][n+5];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=1e9;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int t[k[i]+5]={0};
        for(int j=1;j<=k[i];j++){
             int x;
             cin>>x>>t[i];
             e[i].push_back(x);
             a[x].push_back(i);
             v[x].push_back(t[i]);
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<a[i].size();j++)
            for(int l=0;l<j;l++){
                int x=min(d[a[i][j]][a[i][l]],v[i][j]+v[i][l]);
                d[a[i][j]][a[i][l]]=d[a[i][l]][a[i][j]]=x;
            }
    for(int i=1;i<=3;i++){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(k==i||k==j) continue;
                    int x=min(d[i][j],d[i][k]+d[j][k]);
                    d[i][j]=d[j][i]=x;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) d[i][i]=0;
    while(q--){
        int x,y,ans=1e9;
        cin>>x>>y;
        for(int i=0;i<a[x].size();i++)
            for(int j=0;j<a[y].size();j++){
                ans=min(ans,d[a[x][i]][a[y][j]]+v[x][i]+v[y][i]);
            }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
//我已急哭
//13:46 闪击掉T1
//16:49 剩下三道题暴力都敲不出来
//16:53 T2有思路了

//很潦草的最短路，忘背模板了TAT
//正确率不到95%
//要是没有多测我说不定就骗到分了QAQ
//不爆零就行
//rp++
//rp++

//差点忘改freopen了

//给点分吧哥算我求你了
//要是一等我把你放家里供着