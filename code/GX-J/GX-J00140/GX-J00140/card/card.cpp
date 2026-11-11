#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[100];
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]
    }
    for(int i=1;i<=4;i++){

        sum=sum+a[i];
    }


cout<<sum;

return 0;
}

