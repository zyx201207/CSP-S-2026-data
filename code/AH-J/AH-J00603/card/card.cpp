#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        int s[m+2],q[n-i+2],k=1,ans=0;
        for(int j=1;j<=m;j++)s[j]=-1;
        for(int j=i;j<=n;j++){
            if(s[a[j]]==-1||(s[a[j]]!=-1&&s[a[j]]>=k)){
                q[k]=a[j];
                s[a[j]]=k++;}
            else k=s[a[j]]+1;
        }
        for(int j=1;j<k;j++)if(q[j]==i)ans++;
        printf("%d ",ans);
    }
    return 0;
}
