#include<bits/stdc++.h>
using namespace std;
int n, m, a[300005], sum[300005], cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(sum[a[j]]>0){
                for(int k=i;k<j;k++){
                    if(a[k]==a[j]){
                        for(int q=k;q<j;q++)
                            sum[a[q]]=0;
                    }
                }
            }
            sum[a[j]]++;
        }
        for(int j=1;j<=m;j++){
            if(sum[j]!=0){
                cnt[j]+=sum[j];
                sum[j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<" ";
    return 0;
}
