#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+10;
const int maxm=1e5+10;
int n,m,a[maxn],b[maxm];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        stack<int> now;
        bool ap[maxm];
        memset(ap,false,sizeof(ap));
        for(int j=i;j<=n;j++){
            if(!ap[a[j]]){
                ap[a[j]]=true;
            }else{
                while(now.top()!=a[j]){
                    ap[now.top()]=false;
                    now.pop();
                }
                now.pop();
            }
            now.push(a[j]);
        }
        while(!now.empty()){
            b[now.top()]++;
            now.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<' ';
    cout<<'\n';
    return 0;
}
