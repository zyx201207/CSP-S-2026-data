#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005];
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        bool z=0;
        for(int j=i;j<=n;j++){
            if(a[i]==a[j]){
                z=1;
                break;
            }
        }
        if(z!=0) ans[a[i]]+=i;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
