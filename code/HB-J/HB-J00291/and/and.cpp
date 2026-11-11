#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,a[200005];
bool vis[200005];
void f(long long x,long long cnt){
    if(x>m){
        maxx=max(maxx,cnt);
        return;
    }
    for(int i=0;i<n;i++){
        if(vis[i])continue;
        vis[i]=1;
        if(x==1) f(x+1,a[i]);
        else f(x+1,cnt&a[i]);
        vis[i]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    f(1,0);
    cout<<maxx;
    return 0;
}
