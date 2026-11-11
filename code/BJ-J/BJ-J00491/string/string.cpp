#include<bits/stdc++.h>
using namespace std;
using Ull = unsigned long long;
constexpr Ull N = 2e5+10;
int n;
Ull a[N],cnt;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i]>>c[i];

    int i = 0,j = n-1;
    while(i<j){
        Ull lm = min(a[i],a[j]);
        a[i]-=lm,a[j]-=lm;
        if(c[i]!=c[j])
            cnt+=lm;
        if(a[i]==0) ++i;
        if(a[j]==0) --j;
    }
    cout<<cnt<<flush;
    return 0;
}
