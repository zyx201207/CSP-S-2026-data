#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200000],cnt[200000],f[200000],out[200000];
int main(){
    freopen("card.in","r",stdin);
    cin>>n>>m;;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(cnt[a[i]]!=0){
            for(j=0;j<n;j++){
                f[j]=0;
            }
            f[a[i]]=1;
        }
        cnt[a[i]]++;
    }
    for(i=0;i<n;i++){
        for(j=i;i<n;i++){
            if(cnt[a[i]]!=0){
                for(k=0;k<n;k++){
                    f[k]=0;
                }
                f[a[i]]=1;
            }
        }
        for(h=0;h<n;h++){
            if(f[a[h]]) out[h]++;
        }
    }
    for(i=0;i<n;i++){
        cout<<out[i];
    }
    freopen("card.out","w",stdout);
    return 0;
}
