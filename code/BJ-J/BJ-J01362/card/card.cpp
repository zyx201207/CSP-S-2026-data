#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,ans[N],a[N],f[N],len=1,k;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof f);
        len=i;
        for(int j=i;j<=n;j++){
            f[a[j]]++;
            if(f[a[j]]==2){
                f[a[j]]=1;
                k=j-1;
                while(a[k]!=a[j]&&k>=len){
                    f[a[k]]=0;
                    k--;
                }
                len=j;
            }
        }
        for(int j=len;j<=n;j++){
            ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
