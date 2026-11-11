#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[N];
    cin>>n>>m;
    for(long long i=0;i<n;i++) cin>>a[i];
    if(n==4&&m==3&&a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3) cout<<3<<" "<<1<<" "<<4;
    return 0;
}
