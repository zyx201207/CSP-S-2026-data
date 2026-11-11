#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ai,k,l;
    char ci;
    cin>>n;
    char string a[n];
    for(int i=1;i<=n){
        cin>>ai;
        cin>>ci;
        for(int j=i;j<=ai;j++){
            a[j]=ci;
        }
        i+=a[i];
    }
    for(k=1;k<=n;k++){
        for(l=n;l>=1;l--){
            if(a[k]!=a[l]) a[l]=a[k];
            else continue;
        }
    }
    for(int i=1;i<=n;i++) cout<<a[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}