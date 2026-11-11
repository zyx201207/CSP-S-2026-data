#include<bits/stdc++.h>
using namespace std;
int n,m;
int card[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&card[i]);
    }
    for(int i=1;i<=m;i++){
        cout<<card[1]<<' ';
    }

    return 0;
}
