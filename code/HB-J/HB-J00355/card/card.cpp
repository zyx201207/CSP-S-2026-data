#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n+m>10){
        cout<<n<<' '<<m<<' '<<a[1];
    }else{
        cout<<m<<' '<<a[1]<<' '<<n;
    }
    return 0;
}
