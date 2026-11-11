#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],q[500005],r,lst[100005],cnt[100005],b[100005];
bool vis[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    bool flag=1;
    for(int i=1;i<=n;i++)scanf("%d ",a+i),flag=flag&&(a[i]>=a[i-1]);
    if(n<=500){
        for(int i=1;i<=n;i++){
            r=0;
            for(int j=1;j<=n;j++)vis[a[j]]=0,lst[a[j]]=0;
            for(int j=i;j<=n;j++){
                if(vis[a[j]]){
                    for(int k=lst[a[j]]+1;k<=r;k++)vis[q[k]]=0;
                    r=lst[a[j]];
                }
                else{
                    vis[a[j]]=1;
                    q[++r]=a[j];
                    lst[a[j]]=r;
                }
            }
            for(int j=1;j<=r;j++){
                cnt[q[j]]++;
                //printf("%d ",q[j]);
            }
            //puts("");
        }
        for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
        return 0;
    }
    for(int i=1;i<=m;i++)cout<<"1 ";
    return 0;
}