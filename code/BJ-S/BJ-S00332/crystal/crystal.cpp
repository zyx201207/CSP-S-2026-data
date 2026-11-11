#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b,c;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c=0;
        for(int j=1;j<=i;j++){
            c+=a[j];
        }
        if(c+m>=(i-1)*a[i]){
            b=i;
        }
    }
    cout<<b;
    return 0;
}