#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
long long a[N]={};
bool vis[N]={};
int ansx=-1;
int ans=-1;
int t=0;

int aanndd(long long x,long long y){
    int ssuumm=0;
    int xx,yy;
    while(x<0){
        xx+=x%2;
        x/=2;
    }
    while(y<0){
        yy+=y%2;
        y/=2;
    }
    string xxx,yyy;
    while(xx<0){
        xxx.push_back(xx%10);
        x/=10;
    }
    while(yy<0){
        yyy.push_back(yy%10);
        y/=10;
    }
    for(int i=1;i<=max(xxx.size(),yyy.size());i++){
        if(xxx[i]==yyy[i]){
            ssuumm+=pow(2,i-1);
        }
        else{

        }
    }
}
void dfs(int c){
    if(c==m){
        ansx=max(ansx,ans);
        return;
    }
    for(int i=1;i<=n;i++){
        if(t==0){
            ans=aanndd(a[i],a[i]);
            t++;
            vis[i]=1;
            dfs(c+1);
        }
        if(vis[i]==0){
            ans=aanndd(ans,a[i]);
            vis[i]=1;
            dfs(c+1);
            vis[i]=0;
        }
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ansx;
}
