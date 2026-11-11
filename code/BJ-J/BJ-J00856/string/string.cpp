#include <bits/stdc++.h>
#define int long long
using namespace std;
struct unit{
    int num;
    char c;
}a[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
    }
    int l=1,r=n,cnt=0;
    while(l<r){
        int tmp=min(a[l].num,a[r].num);
        a[l].num-=tmp;
        a[r].num-=tmp;
        if(a[l].c!=a[r].c) cnt+=tmp;
        if(a[l].num==0) l++;
        if(a[r].num==0) r--;
    }
    cout<<cnt<<'\n';
    return 0;
}
