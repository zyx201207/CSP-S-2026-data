#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510],a[510][500010],t[510][500010];
long long s[510][510];
vector<int>zh[500010];
int lo[100010],ro[100010];
int book2[510],book[510][5010];
void dfs(int op,int mow,long long w,int lp,long long kk){
    s[op][mow]=min(s[op][mow],kk);
    for(int i=1;i<=k[lp];i++){
        if(book[lp][a[lp][i]]==0){
            book[lp][a[lp][i]]=1;
            dfs(op,a[lp][i],w,lp,w);
            book[lp][a[lp][i]]=0;
        }
    }int len=zh[mow].size();
    for(int i=0;i<len;i++){
        if(zh[mow][i]==lp)continue;
        if(book[zh[mow][i]][mow]==0){
            book[zh[mow][i]][mow]=1;
            dfs(op,mow,w+t[lp][mow]+t[zh[mow][i]][mow],zh[mow][i],w);
            book[zh[mow][i]][mow]=0;
        }
    }return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            zh[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>lo[i]>>ro[i];
        book2[lo[i]]=1;
    }
    for(int i=1;i<=m;i++){
        memset(book,0,sizeof book);
        for(int j=1;j<=m;j++){
            s[i][j]=0x3f3f3f3f;
        }for(int j=0;j<zh[i].size();j++)book[zh[i][j]][i]=1;
        dfs(i,i,0,zh[i][0],0);
        for(int j=1;j<=m;j++){
            cout<<s[i][j]<<' ';
        }cout<<endl;
    }
    for(int i=1;i<=q;i++){
        cout<<s[lo[i]][ro[i]]+w[lo[i]]+w[ro[i]]<<'\n';
    }
    return 0;
}
