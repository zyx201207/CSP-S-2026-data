#include<bits/stdc++.h>
using namespace std;
int n,m,last[300005],a[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        last[a[i]]=i;
    }
    for(int x=1;x<=n;x++){
        int oooo=x;
        while(oooo<=n){
            ans[a[oooo]]++;
            int newo=last[a[oooo]]+1;
            oooo=newo;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
