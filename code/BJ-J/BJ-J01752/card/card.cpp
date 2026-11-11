#include<bits/stdc++.h>
using namespace std;
bool flag[300010];
int a[500010];
int ans[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)flag[j]=0;
        queue<int> q;
        for(int j=i;j<=n;j++){
            if(flag[a[j]]){
                while(q.front()!=a[j]){
                    flag[q.front()]=0;
                    q.pop();
                }
            }
            else{
                q.push(a[j]);
                flag[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++)if(flag[j])ans[j]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}