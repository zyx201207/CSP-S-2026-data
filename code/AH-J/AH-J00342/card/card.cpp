#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005],f[300005],x[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(t,0,sizeof(t));
        long long ls=0;
        for(int j=i;j<=n;j++){
            t[a[j]]++;
            if(t[a[j]]==1){
                x[a[j]]=j;
            }
            if(t[a[j]]==2){
                for(int k=x[a[j]];k<=j-1;k++){
                    x[a[k]]=0;
                    t[a[k]]--;
                }
                x[a[j]]=j;
                //t[a[j]]++;
            }
        }
        for(int j=1;j<=m;j++){
            if(t[j]>=1){
                f[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<f[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

