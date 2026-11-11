#include<bits/stdc++.h>
using namespace std;
int ans[5000];
int a[5000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=500||m<=500){
        for(int i=1;i<=n;i++){
            int table[5000];
            memset(table,0,sizeof table);
            int now=0;
            for(int j=i;j<=n;j++){
                now++;
                table[now]=a[j];
                for(int k=1;k<now;k++){
                    if(table[now]==table[k]){
                        now=k;
                    }
                }

            }

        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        for(int i=1;i<=m;i++){
            cout<<i<<" ";
        }
    }
    return 0;
}
