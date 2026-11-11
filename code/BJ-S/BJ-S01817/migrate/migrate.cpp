#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000005];
int bfs(int x,int y,int d,int n){
    queue<int> q;
    q.push(x);
    bool b=0;
    int res=0;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        if(f==y){
            b=1;
            res++;
        }
        if(b)continue;
        for(int i=0;i<n;i++){
            if(a[i]-a[f]<=d&&i>f){
                q.push(i);
            }
        }
    }
    return res;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(bfs(i,j,d,n)==3){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
