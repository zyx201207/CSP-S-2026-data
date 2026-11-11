#include<bits/stdc++.h>
using namespace std;
int a[500005];
int e[200005];
int t[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        e[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=e[i];j<=n;j++){
            t[a[j]]++;
            if(j!=e[a[j]]){
                j=e[a[j]];
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
return 0;
}
