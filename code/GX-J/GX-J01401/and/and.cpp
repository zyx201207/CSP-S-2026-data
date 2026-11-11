#include<bits/stdc++.h>
using namespace std;
int num[500005]={0};
int n,m;
long long mans=0;
void dfs(int x,long long nans,int lst){
    if(x==m){
        mans=max(mans,nans);
        return;
    }
    for(int i=lst+1;i<=n;i++){
        dfs(x+1,(nans&num[i]),i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    dfs(0,INT_MAX,0);
    cout<<mans;
    return 0;
}

