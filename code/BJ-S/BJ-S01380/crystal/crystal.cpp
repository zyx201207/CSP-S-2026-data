#include<bits/stdc++.h>
using namespace std;
long long n,m,mm,a[500005],g=1,maxx=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    mm=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i!=1){
            m+=a[g]-a[i-1];
        }
        while(m>=(a[g+1]-a[g])*(g-i+1)&&g<=n){
            m-=(a[g+1]-a[g])*(g-i+1);
            g++;
        }
        maxx=max(maxx,g-i+1);
    }

    cout<<maxx;
    return 0;
}
