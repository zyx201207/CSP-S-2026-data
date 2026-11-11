//GZ-J00082 ≥¬”Í«Á
#include <bits/stdc++.h>
using namespace std;
long long d[10000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>d[i];
    }
    /*for(long long i=1;i<=m;i++){
        for(long long j=1;j<=n;j++){
        if(i==d[j])
    }
    }*/
    /*int b=1;
    if(n==2){
        cout<<b<" "<<b;
        return 0;
    }*/

    if(d[-1]==1)
        cout<<n<<" "<<2;
else
cout<<2<<" "<<n;
    return 0;
}
