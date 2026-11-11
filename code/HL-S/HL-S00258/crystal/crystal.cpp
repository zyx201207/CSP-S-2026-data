#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cha,cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,greater<int>());
    cha=a[0]-a[1];
    cnt=m/cha;
    cout<<min(cnt+1,n);
    return 0;
}
