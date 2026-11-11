#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","W",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(m>=(a[i+1]-a[i])*i){
            sum++;
            m-=(a[i+1]-a[i])*i;
            for(int j=1;j<=i;j++)
                a[j]=a[i+1];
        }
        else
            return 0;
    }
    cout<<sum+1;
    return 0;
}
