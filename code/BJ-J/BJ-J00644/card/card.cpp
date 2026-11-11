#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int s[300005];
int z[300005];
int nxt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        nxt[z[i]]=i;
        z[i]=i;
    }
    for(int i=1;i<=n;i++){
        memset(z,0,sizeof(z));
        for(int j=i;j<=n;){
            if(nxt[j]!=0)j=nxt[j];
            else z[j]++,j++;
        }
        for(int j=1;j<=m;j++){
            if(z[j]!=0){
                s[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
