#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,t[200005],sum[200005];
    cin>>n>>m;
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        t[x]++;
    }
    for(int i=1;i<=m;i++){
        sum[i]=sum[i-1]+t[i];
        cout<<sum[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
