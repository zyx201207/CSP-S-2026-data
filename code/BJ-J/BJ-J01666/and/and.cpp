#include<bits/stdc++.h>
using namespace std;
int tablenum[1010101];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long x;
        scanf("%lld",&x);
        tablenum[i]=x;
    }
    sort(tablenum+1,tablenum+1+n);
    int ans=tablenum[n];
    for(int i=n;i>=0;i--,m--){
        if(!(m>0))break;
        ans=ans&tablenum[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
