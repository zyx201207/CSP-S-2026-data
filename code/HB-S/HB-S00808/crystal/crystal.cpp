#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,a[500005],b[500005]={0},c[500005]={0},max=0;
    long long m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int k=1;
        for(int j=i+1;j<n;j++){
            b[j]=a[j]-a[i];
            k+=b[j];
            if(k-m>0){
                c[i]=j-i;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(max<c[i]){
            max=c[i];
        }
    }
    cout<<max;
    return 0;
}
