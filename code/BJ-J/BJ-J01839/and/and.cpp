#include<bits/stdc++.h>
using namespace std;
int n,m;
long long max_num=-999;
vector<long long> a;
void dfs(long long re,int i,int j){
    if(j==m){
        max_num=max(max_num,re);
        return ;
    }
    if(i>n)
        return;
    if(re==0){
        dfs(a[i],i+1,j+1);
    }
    else
        dfs(re&a[i],i+1,j+1);
    dfs(re,i+1,j);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    dfs(0,0,0);
    cout<< max_num;
    return 0;
}
