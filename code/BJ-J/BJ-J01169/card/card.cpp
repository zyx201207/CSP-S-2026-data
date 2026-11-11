#include <bits/stdc++.h>
using namespace std;
int n,m,k,rt;
int kards[300005],cnt[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>kards[i];
    }

    for(int c=1;c<=n;c++){
        int table[300005][3]={},rt=1;
        for(int i=1;i<=m+1;i++){

            k=kards[c+rt-1];
            if(table[k][2]==0){
                table[rt][1]=k;
                table[k][2]=rt;
            }else if(table[k][2]!=0 && table[k][1]!=0){
                rt=table[k][2];
                for(int v=table[k][2];v<=m;v++){
                    table[v][1]=0;table[v][2]=0;
                }
                table[rt][1]=k;table[k][2]=rt;
            }
            rt++;
        }
        for(int i=1;i<=n+1;i++){
            cnt[table[i][1]]++;
        }

    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}