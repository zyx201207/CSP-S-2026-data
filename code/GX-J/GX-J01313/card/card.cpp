#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long p[n+10],cnt[m+10]={};
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++){
        long long a[n+10],l=0,r=0;
        for (int j=i;j<=n;j++){
            if (l==0) l++;
            else{
                for (int k=l;k<=r;k++){
                    if (a[k]==p[j]){
                        r=k-1;
                        break;
                    }
                }
            }
            r++;
            a[r]=p[j];
        }
        for (int j=1;j<=r;j++) cnt[a[j]]++;
    }
    for (int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
