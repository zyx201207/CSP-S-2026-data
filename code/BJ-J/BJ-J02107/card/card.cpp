#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5009],b[5009],t[5009],ans[5009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int r=1;
        for(int j=1;j<=n;j++){
            t[j]=-1;
            b[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(t[a[j]]==-1){
                b[r]=a[j];
                t[a[j]]=r;
                r++;
            }else{
                for(int k=t[a[j]]+1;k<=r;k++){
                    t[b[k]]=-1;
                }
                r=t[a[j]]+1;
            }
        }
        for(int j=1;j<=r-1;j++){
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
