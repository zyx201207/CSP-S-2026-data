#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],tt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int t[500005]={0},ed=i,st=i,b[500005]={0};
        for(int j=i;j<=n;j++){
            t[a[j]]++;
            b[a[j]]=min(j,b[a[j]]);
            if(t[a[j]]>=2){
                ed=j;
                st=b[a[j]];
            }
        }
        for(int j=i;j<=st-1;j++) tt[a[j]]++;
        for(int j=ed;j<=n;j++) tt[a[j]]++;
    }
    for(int i=1;i<=m;i++){
        cout<<tt[i]<<" ";
    }
    return 0;
}
