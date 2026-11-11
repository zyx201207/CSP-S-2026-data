#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int n,m,i,j;
struct NS{
    int xh;
    bool cx;

};
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    int b[1000000];
    int ans[m+1];
    for(i=1;i<=m;i++){
        ans[i]=0;
    }
    for(i=1;i<=n;i++){
        NS x[m+1];
        for(j=1;j<=m;j++){
            x[j].xh=0;
            x[j].cx=0;
        }
        for(j=i;j<=n;j++){
            b[j]=a[j];
        }
        for(j=i;j<=n;j++){
            if(x[j].cx==0){
                x[j].cx=1;
                x[j].xh=j;
            }
            else{
                x[j].cx=0;
                for(int p=x[j].xh;p<j;p++){
                    b[p]=0;
                }
            }

        }
        int sum[m+1];
        /*for(j=1;j<=m;j++){
            sum[j]=0;
        }*/
        /*for(j=i;j<=n;j++){
                if(sum[b[j]]==0){
                    ans[b[j]]++;
                    sum[b[j]]++;
                }*/

        }
    }






    return 0;
}
