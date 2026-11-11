#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005];
bool b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    memset(b,1e9+7,sizeof(b));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!b[a[i]]){
            c[a[i]]=i;
            b[a[i]]=true;
        }else{
            for(int j=c[a[i]]+1;j<i;j++){
                c[a[j]]-=c[a[i]];
            }
            c[a[i]]=i;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
