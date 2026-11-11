#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    int n,m,sum;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a[0],a[n]);
    sum=a[0]&a[1];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum=max(sum,a[i]&a[j]);
        }
    }
    cout<<sum;
    return 0;
}
