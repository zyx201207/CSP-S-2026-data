#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[20010]={},f[20010]={};
    int f1[20010]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0]=2147483647;
    for(int j=1;j<=m;j++){
            int z;
    for(int i=1;i<=n;i++){
            bool f2=1;
    for(int i1=1;i1<j;i1++){
                if(f1[i1]==i){
                    f2=0;
                    break;
                }
            }
            if(!f2) continue;
        if(f[j]<f[j-1]&a[i]){
          f[j]=f[j-1]&a[i];
            z=i;
            }
        }
        f1[j]=z;
        }
    cout<<f[m];
    return 0;
}
