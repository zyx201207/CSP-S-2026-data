#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Block
{

    ll len;
    char ch;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Block> blk(n);
    for(int i=0;i<n;i++)
    {
        cin>>blk[i].len>>blk[i].ch;

    }
    int l=0,r=n-1;
    int ans=0;
    while(l<r)
    {
        ll L=blk[l].len;
        ll R=blk[r].len;
        char cl=blk[l].ch;
        char cr=blk[r].ch;
        ll take=min(L,R);
        if(cl!=cr) ans+=take;
        blk[l].len-=take;
        blk[r].len-=take;
        if(blk[l].len==0) l++;
        if(blk[r].len==0) r++;
    }
    cout<<ans;
    return 0;
}
