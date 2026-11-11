#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,res=0;
struct node{int num;char c;}a[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
    int l=1,r=n;
    while(l<r){
        int minn=min(a[l].num,a[r].num);
        if(a[l].c!=a[r].c) res+=minn;
        a[l].num-=minn;
        a[r].num-=minn;
        if(!a[l].num) l++;
        if(!a[r].num) r--;
    }
    cout<<res<<"\n";
    return 0;
}