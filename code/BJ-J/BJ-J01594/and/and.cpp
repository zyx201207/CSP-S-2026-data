#include<bits/stdc++.h>
using namespace std;
int a[20005];
int n,m,ma=pow(2,32)-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    sort(a+1,a+1+n);
    for(int i=n;i>n-m;i--){
        ma&=a[i];
    }
    cout<<ma;

    return 0;
}
