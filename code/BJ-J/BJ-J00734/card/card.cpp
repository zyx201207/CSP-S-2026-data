#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],b[N],ans[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        int tot=0;
        for(int j=i;j<=n;j++){
            bool ok=true;
            for(int k=1;k<=tot;k++){
                if(b[k]==a[j]){
                    tot=k;
                    b[k]=a[j];
                    for(int l=k+1;l<=tot;l++)
                        a[k]=0;
                    ok=false;
                    break;
                }
            }
            if(ok)b[++tot]=a[j];
        }
        for(int j=1;j<=tot;j++)
            ans[b[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}