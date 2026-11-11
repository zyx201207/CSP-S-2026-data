#include<bits/stdc++.h>
using namespace std;


long long a[500005];
long long n,m,maxn;

void dfs(int d,long long s,int cho,long long data){
    //cout<<"d="<<d<<",s="<<s<<",cho="<<cho<<",data="<<data<<".\n";
    if(m-cho>n-d||s<=maxn)return;
    if(cho==m){
        if(maxn<s){
            maxn=max(maxn,s);
            //cout<<"Let's change the maxn to s:"<<maxn<<".\n";
        }
        return;
    }
    if(d>n){
        //cout<<"d==n,data="<<data<<".\n";
        return;
    }
    dfs(d+1,s&a[d],cho+1,data*10+1);
    dfs(d+1,s,cho,data*10);
    return;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0xffffff,0,0);
    cout<<maxn;
    return 0;
}
