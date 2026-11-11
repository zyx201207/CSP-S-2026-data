#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn;
bool f[200005];
void dfs(int x,int cnt,long long yh){

    if(cnt==m){
        maxn=max(yh,maxn);
    }
    //cout<<x<<" "<<cnt<<" "<<yh<<" "<<maxn<<"\n";
    cnt++;
    for(int i=x;i<=n;i++){
        if(!f[i]){
            f[i]=1;
            dfs(i,cnt,yh&a[i]);
            f[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f[i]=1;
        dfs(i,1,a[i]);
        f[i]=0;
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//&与
