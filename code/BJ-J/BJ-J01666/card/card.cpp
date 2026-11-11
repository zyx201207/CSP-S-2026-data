#include<bits/stdc++.h>
using namespace std;
struct qwe{
    int value;
    int pre;
    bool biaoji;
}a[101010];
int table[101010];
int tablenum[101010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(table,0x3f,sizeof(table));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].value);
        a[i].pre=table[a[i].value];
        table[a[i].value]=i;
        a[i].biaoji=false;
    }

    for(int i=1;i<=n;i++){
        int pre=0;
        for(int j=i;j<=n;j++){
            if(  a[j].pre<=n  &&  a[a[j].pre].biaoji==false  &&  a[j].pre>=i){
           //     cout<<j<<" "<<a[j].pre<<endl;
                for(int k=a[j].pre;k<j;k++){
                    a[k].biaoji=true;
                }
            }
        }
        bool falg[101010];
        memset(falg,false,sizeof(falg));
        for(int j=i;j<=n;j++){
            if(a[j].biaoji==false&&!falg[a[j].value]){
             //   cout<<a[j].value<<" ";
                tablenum[a[j].value]++;
                falg[a[j].value]=true;
            }
            a[j].biaoji=false;
        }
       // cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<tablenum[i]<<" ";
    }
    return 0;
}
