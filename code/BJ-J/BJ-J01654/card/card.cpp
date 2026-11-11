#include<bits/stdc++.h>
using namespace std;
int a[5009],b[3009],m,n,l,ans[3009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            int k=0;
            for(int j=i;j<=n;j++){
                    k++;
                for(int h=1;h<k;h++){
                   if(a[j]==b[h])k=h,l=1;
                }
                if(l!=1)b[k]=a[j];
                l=0;
            }
                for(int i=1;i<=k;i++){
                ans[b[i]]+=1;
            }
            }
            for(int i=1;i<=m;i++){
                cout<<ans[i]<<" ";
            }
    return 0;
}