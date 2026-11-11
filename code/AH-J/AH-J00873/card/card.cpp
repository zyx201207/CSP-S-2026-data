#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
stack<LL> q;
LL a[500010],cnt[300010];
bool f[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof f);
        for(int j=i;j<=n;j++){
            if(f[a[j]]==0){
                f[a[j]]=1;
                q.push(a[j]);
            }
            else{
                while(q.top()!=a[j]){
                    f[q.top()]=0;
                    q.pop();
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(f[j]) cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}

