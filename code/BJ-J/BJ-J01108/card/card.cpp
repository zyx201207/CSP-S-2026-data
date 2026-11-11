#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int ans[300005];
int flag[300005];
int u[300005];
stack<int>s;

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(flag[a[j]]==0){
                s.push(a[j]);
                flag[a[j]]=1;
            }
            else{
                while(s.top()!=a[j]) s.pop();
            }
        }
        while(s.size()){
            if(u[s.top()]==0){
                ans[s.top()]++;
                u[s.top()]=1;
            }
            s.pop();
        }
        memset(flag,0,sizeof(flag));
        memset(u,0,sizeof(u));
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";

    return 0;
}
