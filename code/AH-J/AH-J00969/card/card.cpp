#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int v[300005];
int b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]]=i;

    }
//    cout<<1<<endl;
/*    for(int i=1;i<=m;i++){
        printf("%d ",v[i]);
    }
    cout<<endl;*/
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            j=v[a[j]];
            b[a[j]]++;
        }
        /*for(int j=1;j<=m;j++){
            printf("%d ",b[j]);
        }
        printf("\n");*/
    }
    for(int i=1;i<=m;i++){
        printf("%d ",b[i]);
    }
    return 0;
}
