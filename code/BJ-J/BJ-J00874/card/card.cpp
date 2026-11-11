#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N],c[N],cnt,last[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
 //   if(n<=2000){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) last[j]=0;
            cnt=0;
            for(int j=i;j<=n;j++){
                if(last[a[j]]==0){
                    last[a[j]]=cnt+1;
                    c[++cnt]=a[j];
                }else{
                    for(int k=last[a[j]]+1;k<=cnt;k++){
                        last[c[k]]=0;
                    }
                    cnt=last[a[j]];
                }
            }
            for(int j=1;j<=cnt;j++){
         //       cout<<c[j]<<" ";
                ans[c[j]]++;
            }
        //    cout<<endl;
        }
  //  }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
