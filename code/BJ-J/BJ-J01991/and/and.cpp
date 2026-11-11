#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    frepoen("and.out","w",stdout);
    int m,n,siu[789],sum=0,k[987],r;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=m;i++){
        siu[i]=a[i]|a[i-1];
        sum=max(sum,siu[i]);
    }
    for(int i=m;i<=n;i++){
        k[i]=sum||a[i];
        r=max(k[i],k[i-1]);
    }
    cout<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
