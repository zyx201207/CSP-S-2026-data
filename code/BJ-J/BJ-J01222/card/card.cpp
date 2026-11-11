#include<bits/stdc++.h>
using namespace std;
stack<int> __;
long long a[600001],n,m,cnt[600001];bool in[600001];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(in,0,sizeof(0));
        for(int j=i;j<=n;j++){
            if(in[a[j]]){while(__.top()!=a[j])__.pop();in[a[j]]=0;}
            else {
                __.push(a[j]);
                in[a[j]]=1;
            }
        }
        while(__.size()) {
            cnt[__.top()]++;
            __.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
