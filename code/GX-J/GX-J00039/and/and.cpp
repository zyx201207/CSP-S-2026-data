#include <bits/stdc++.h>
using namespace std;
int a[10000086];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,p,b,s;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    s=a[n];
    for(int i=n;i>=1;i--){
        s&=a[i];p--;
        if(p<1)break;
    }
    cout<<s;
    return 0;
}
