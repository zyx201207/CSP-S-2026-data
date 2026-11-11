#include <bits/stdc++.h>
using namespace std;
int n,m,a[500100],b[500100],cnt[300100],p[300100],ans,an;
bool c[300100];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ans=i;
        for(int j=i;j<=n;j++,ans++){
            if(c[a[j]]==true){
                while(ans!=p[a[j]]){
                    ans--,c[b[ans]]=false,p[a[ans]]=0,b[ans]=0;
                }
            }
            b[ans]=a[j],c[a[j]]=true,p[a[j]]=ans,an=ans;
        }
        for(int j=i;j<=an+i;j++)c[b[j]]=false;
        for(int j=i;j<=an+i;j++)cout<<b[j]<<" ";
        cout<<endl;
        for(int j=i;j<=an+i;j++)cnt[b[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    cout<<endl;
    return 0;
}
