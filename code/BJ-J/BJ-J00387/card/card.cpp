#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500002];
int pai[500002],to=0;
int ans[300002];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int t=0;t<n;t++){
            to=0;
        for(int i=t;i<n;i++){
            for(int j=to-1;j>=0;j--){
                if(pai[j] == a[i]){
                    to=j;
                    break;
                }
            }
            pai[to++]=a[i];
        }
        for(int i=0;i<to;i++){
            ans[pai[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
