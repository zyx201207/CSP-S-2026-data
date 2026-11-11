#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,tot=1;
int a[N],ans[N],xu[N];
void fd(int x){
    for(int i=1;i<tot;i++){
        if(xu[i]==x){
            tot=i;
            return ;
        }
    }
    return ;
}
signed main(){
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        tot=1;
        for(int j=n-i+1;j<=n;j++){
            fd(a[j]);
            xu[tot]=a[j];
            tot++;
        }
        for(int j=1;j<tot;j++){
            //cout<<xu[j]<<" ";
            ans[xu[j]]++;
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
