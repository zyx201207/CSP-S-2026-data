#include <bits/stdc++.h>
using namespace std;
int g[1000][1000],n,d;
int x[1000],cnt,len,vis[1000];
int res[1000],end;
queue <int> q;
const int INF=624624;
string s;
void search(int x)[
    len++;
    vis[x]=1;

    if(x==end){
        cnt++;
        return ;
    }

    for(int i=1;i<=n;i++){
        if(g[x][i]==1 && vis[i]==0){
            search(i);
        }
    }
]




int main(){
    //int c,t;
    //cin>>c>>t;
    //while(t--){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        a[i][i]=INF;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int dis=abs(x[i]-x[j])
            if(dis<=d){
                a[i][j]=a[j][i]=1;//liantong
            }   
        }
    }
    
    for(int i=1;i<=n;i++){
        search(i);
        res[i]=cnt;
    }
    
    return 0;
}