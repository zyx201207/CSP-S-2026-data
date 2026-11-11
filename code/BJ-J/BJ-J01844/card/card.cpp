#include<bits/stdc++.h>
using namespace std;
int n,m,ans[3000020];
int a[5000020];
int head,tail;
int b[5000020];
int flag[3000020];
void spfa(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            head++;
            b[head]=a[j];
            if(flag[a[j]]==0){
                flag[a[j]]++;
            }
            else if(flag[a[j]]==1){
                flag[a[j]]++;
                int x=head-1;
                while(b[x]!=a[j]){
                    flag[b[x]]--;
                    b[x]=0;
                    head--;
                    b[head]=a[j];
                    b[head+1]=0;
                    x--;
                }
                flag[b[head]]--;
                b[head]=0;
                head--;
            }
        }
        for(int j=1;j<=head;j++){
            ans[b[j]]++;
        }
        for(int j=1;j<=head;j++){
            b[j]=0;
        }
        head=0;
        for(int p=1;p<=m+1;p++){
            flag[a[p]]=0;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    spfa();
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}

