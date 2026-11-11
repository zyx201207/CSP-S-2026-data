#include<bits/stdc++.h>
using namespace std;
int n,m,a[100100];
int maxn=-0x3f;
void dfs(int x,int y,int cnt){
    if(y==m){
        maxn=max(maxn,cnt);
        return ;
    }
    if(y==0&&x<n-1){
        dfs(x+1,y+1,a[x]);
        dfs(x+1,y,cnt);
    }
    if(x<n) dfs(x+1,y+1,cnt&a[x]),dfs(x+1,y,cnt);
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==m){
        int cnt=a[0];
        for(int i=1;i<n;i++) cnt=cnt&a[i];
        cout<<cnt;
        return 0;
    }
    if(m==2){
        int maxnn=-0x3f3f3f3f;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) maxnn=max(maxnn,a[i]&a[j]);
        }
        cout<<maxnn;
        return 0;
    }
    if(m==1){
        int maax=-0x3f3f3f3f;
        for(int i=0;i<n;i++) maax=max(maax,a[i]);
        cout<<maax;
        return 0;
    }
    if(m==n-1){
        int maxn=0;
        int cntt=a[1];
        for(int i=1;i<n;i++) cntt=cntt&a[i];
        maxn=max(cntt,maxn);
        cntt=a[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i) cntt=cntt&a[i];
            }
            maxn=max(cntt,maxn);
        }
        cout<<maxn;
        return 0;
    }
    dfs(0,0,1);
    cout<<maxn;
	return 0;
}
