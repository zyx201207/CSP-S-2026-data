#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("cart.in","r",stdin);
    freopen("cart.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[100005],b[100005]={0},c[100005]={0},sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
        c[i]=a[i];
        for(int j=0;j<i;j++){
            if(a[i]==c[j]){
                sum=b[i]-b[j];
                for(int k=j;k<i;k++){
                    c[k]=0;
                }
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        if(c[i]!=0){
            cout<<c[i]<<" ";
        }else{
            continue;
        }
    }
    cout<<sum;
    return 0;
}
