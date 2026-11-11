#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int vis[N],ans[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<=a[i-1]){
            flag=0;
        }
    }

    if(flag==1){
        for(int i=1;i<=m;i++){
            cout<<i<<" ";
        }
        return 0;
    }

    for(int i=1;i<=n;i++){
        stack<int>s;
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==1){
                while(s.top()!=a[j]){
                    int x=s.top(); s.pop();
                    vis[x]=0;
                    ans[x]--;
                }
            }
            else{
                s.push(a[j]);
                vis[a[j]]++;
                ans[a[j]]++;
            }
        }
    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

