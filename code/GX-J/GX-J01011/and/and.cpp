#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    for(int i=1;i<=m;i++){
        b[i]=a[n];
        n--;
    }
    int sum=b[1];
    for(int i=2;i<=m;i++){
        sum=(sum&b[i]);
    }
    cout<<sum;
}
