#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005],r[500005]={-100},r_size=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            bool flag=true;
            for(int k=1;k<=r_size;k++)
                if(a[j]==r[k]){
                    for(int p=r_size;p>=k;p--)
                        r[p]=-100;
                    break;
                }
            r[r_size++]=a[j];
        }
        for(int j=1;j<=r_size;j++)
            if(r[j]>=0)
                ans[r[j]]++;
        for(int j=1;j<=r_size;j++)
            r[j]=-100;
        r_size=1;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
