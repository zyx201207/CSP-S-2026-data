#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500006],b[500006],l=1,r=1,now,ans,nowl=1;//现在的花费，答案，现在的长度
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i < n;++i)b[i] = a[i+1]-a[i];
    while(r <= n){
        if(now <= m){//存下答案准备加仓
            ans = max(ans,nowl);
            now += (r-l+1)*b[r];
            ++r;
            ++nowl;
        }else{
            now -= a[r]-a[l];
            ++l;
            --nowl;
        }
    }
    cout << ans;
    return 0;
}
