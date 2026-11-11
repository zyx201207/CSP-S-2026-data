#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int id[N];
int d[N];
int nxt[N];
long long ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int p=1;p<=n;p++){
        memset(d,0,sizeof d);
        memset(id,0,sizeof id);
        for(int i=p;i<=n;i++){
            if(p==1){
                cin>>a[i];
            }
            if(id[a[i]]&&d[id[a[i]]]==0){
                for(int j=id[a[i]];j<=i-1;j++)d[j]++;
            }
            id[a[i]]=i;
        }
        for(int i=p;i<=n;i++){
            if(d[i]==0){
                ans[a[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
