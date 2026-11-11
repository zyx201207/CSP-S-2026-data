#include<bits/stdc++.h>
using namespace std;

int n,m,step,mx;
int a[200010],vis[200010];
vector<int> v;

int an(){
    int nd=v[0];
    for(int i=0;i<v.size();i++){
        nd=(v[i]&nd);
    }
    return nd;
}

void dfs(){
    if(step==m){
        mx=max(mx,an());
        //(int i=0;i<=v.size();i++) cout<<v[i]<<' ';
        //cout<<endl;
        return ;
    }
    step++;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            v.push_back(a[i]);
            dfs();
            v.pop_back();
            vis[i]=0;
        }
    }
    step--;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //?
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs();
    cout<<mx;
    return 0;
}
