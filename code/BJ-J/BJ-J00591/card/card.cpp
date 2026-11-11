#include<bits/stdc++.h>
using namespace std;
int card[500005],table[300005],f[500005],ans[500005];
int n,ti,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
        ti=1;
        memset(f,0,sizeof(f));
        memset(table,0,sizeof(table));
        for(int j=i;j<=n;j++){
            // fang pai
            table[ti++]=card[j];
            f[card[j]]++;
            //na pai
            if(f[card[j]]>=2){
                f[card[j]]=1;
                int i1=ti-1;
                while(table[i1]!=card[j]){
                    f[table[i1]]--;
                    table[i1--]=0;
                }
                table[i1]=0;
            }
        }
        for(int j=1;j<=m;j++){
            ans[i]+=f[i];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
