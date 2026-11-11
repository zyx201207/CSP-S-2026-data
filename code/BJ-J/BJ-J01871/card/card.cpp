#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=5e5+9,M=3e5+9;
int n,m,a[N],b[N],cnt,c[M],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++,cnt=0){
        for(int j=1;j<=m;j++)c[j]=0;
        for(int j=i;j<=n;j++){
            if(c[a[j]]==0)b[++cnt]=a[j],c[a[j]]=cnt;
            else {
                for(int k=c[a[j]]+1;k<=cnt;k++)c[b[k]]=0;
                cnt=c[a[j]];
            }
        }
        for(int j=1;j<=cnt;j++)ans[b[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}