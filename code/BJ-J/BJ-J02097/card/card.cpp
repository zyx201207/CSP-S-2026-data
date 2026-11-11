#include<bits/stdc++.h>
using namespace std;

int n,m,a[200015],flag[200015],que[200015],ans[300015];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        memset(flag,-1,sizeof(flag));
        //printf("game %d start\n",i);
        int r=0;
        for(int j=i;j<=n;j++){
            //printf("id:%d num:%d flag[a[j]]=%d r=%d\n",j,a[j],flag[a[j]],r);
            if(flag[a[j]]==-1 || flag[a[j]]>r){
                r++;
                que[r]=a[j];//in
                //printf("inbox:%d r=%d\n",a[j],r);
                flag[a[j]]=r;
            }else{
                //printf("del:numid:%d\n",a[j]);
                r=flag[a[j]];
            }
        }
        //printf("over,r=%d\n",r);
        r++;
        while(r--){
            ans[que[r]]++;
            //printf("ans update:id=%d data=%d\n",que[r],ans[que[r]]);
        }
    }
    //printf("run OK!\n");
    for(int i=1;i<=m;i++){
        printf("%d",ans[i]);
        if(i<m) printf(" ");
    }
    printf("\n");
    return 0;
}
