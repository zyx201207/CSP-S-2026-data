#include <bits/stdc++.h>
using namespace std;
long long n,mmax,d;
long long a[2000000000]
int main(){
    freopen("and.in","r",stdin);
    cin>>n>>m;
    if(n==0||m==0){
        cout<<0;
        return 0;
    }
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            for(k=0;k<m;k++){
                d=a[i]&a[j+k];
                    mmax=max(mmax,d)
            }
        }
    }
    cout<<mmax;
    freopen("and.out","w",stdout);
    return 0;
}
