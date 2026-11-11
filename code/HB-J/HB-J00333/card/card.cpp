#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num,j,ans[500005];
bool c=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int z=1;z<=n;z++){
        long long b[500005];
        num=0;
        for(int i=z;i<=n;i++){

            for(j=1;j<=num;j++)
                if(a[i]==b[j]){
                    c=0;
                    break;
                }
            if(c){
                num++;
                b[num]=a[i];
            }else{
                num=j;
                b[num]=a[i];
            }
        }
        for(int i=1;i<=num;i++)
            ans[b[i]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
