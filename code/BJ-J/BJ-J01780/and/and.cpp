#include<bits/stdc++.h>
using namespace std;
int a[200006],n,m;
int dfs(int depth,int rst,int start){
    if(depth>=m){
        //cout<<"rst:"<<rst<<endl;
        return rst;
    }
    int x = 0;
    for(int i = start;i<n-m+depth+1;i++){
        x = max(x,dfs(depth+1,rst&a[i],i+1));
    }
    return x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i < n;i++)cin>>a[i];
    cout<<dfs(0,2147483647,0);
    return 0;
}
