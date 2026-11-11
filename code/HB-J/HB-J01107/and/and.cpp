#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum=a[n];
    for(int i=n;i>n-m;i--){
        sum=sum&a[i];
    }
    cout<<sum;
    return 0;
}
