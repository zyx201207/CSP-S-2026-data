#include <bits/stdc++.h>
using namespace std;
int c,t,pos[2000001];
int ans[2000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin>>n>>k;
        for(int j=1;j<=n;j++)
            cin>>pos[j];
        if(k<pos[2]-pos[1])
            ans[i]=0;
        else
            ans[i]=n-((k+(pos[2]-pos[1])-1)/(pos[2]-pos[1]))*2+1;
    }
    for(int i=1;i<=t;i++)
        cout<<ans[i]<<'\n';
    return 0;
}
