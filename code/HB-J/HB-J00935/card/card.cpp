#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int sum[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int l=1,botton=0;
    for(int i=1;i<=n;i++){
        l=1;
        for(int j=i;j<=n;j++){
            botton=0;
         //   cout<<l<<' ';
            for(int k=i;k<=j;k++){
                if(b[k]==a[j]){
                    l=k+1;
                    botton=1;
                    break;
                }
            }
            if(botton==0){

                b[l]=a[j];
                l++;
            }
        }
     //   cout<<endl;
        for(int j=1;j<=l;j++){
            sum[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
    return 0;
}
