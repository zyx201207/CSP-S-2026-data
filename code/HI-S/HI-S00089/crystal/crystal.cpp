// g++ crystal.cpp -o crystal -O2 -std=c++14 -static

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=5e+5+5;
int n,ans;
ll m,a[N],s[N];
int main(void){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int l=1,r=1;r<=n;r++){
        while(s[r]-s[l-1]+m<a[r]*(r-l+1))l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}