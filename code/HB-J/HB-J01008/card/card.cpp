#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,c[500006],table[500006],point=0;
    int has[500006];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        point=0;
        memset(table,0,sizeof(table));
        for(int j=i;j<=n;j++){
            for(int k=1;k<=point;k++){
                if(table[k]==c[j]){
                    point=k-1;
                }
            }
            table[++point]=c[j];
        }
        for(int k=1;k<=point;k++){
            has[table[k]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<has[i]<<' ';
    }
    return 0;
}
