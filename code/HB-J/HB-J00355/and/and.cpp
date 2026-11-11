#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],max1=0,ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            max1=max(max1,a[i]);
        }
    }
    if(m==2){
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                max1=max(max1,a[i]&a[j]);
            }
        }
    }
    cout<<max1;
    return 0;
}
