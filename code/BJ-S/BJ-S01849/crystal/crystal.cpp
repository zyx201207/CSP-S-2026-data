#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , m , a[500005] , ans = 1;
struct node
{
    int l , r , tag , sum;
};
struct xds
{
    node tree[2000005];
    inline void build(int p , int l , int r)
    {
        tree[p].l = l;
        tree[p].r = r;
        tree[p].tag = 0;
        if(l == r)
        {
            tree[p].sum = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(p * 2 , l , mid);
        build(p * 2 + 1 , mid + 1 , r);
        tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
        return;
    }
    inline void upd(int p , int l , int r , int k)
    {
        if(l <= tree[p].l && tree[p].r <= r)
        {
            tree[p].tag += k;
            tree[p].sum += (tree[p].r - tree[p].l + 1) * k;
            return;
        }
        if(tree[p].tag)
        {
            tree[p * 2].tag += tree[p].tag;
            tree[p * 2].sum += (tree[p * 2].r - tree[p * 2].l + 1) * tree[p].tag;
            tree[p * 2 + 1].tag += tree[p].tag;
            tree[p * 2 + 1].sum += (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1) * tree[p].tag;
            tree[p].tag = 0;
        }
        if(tree[p * 2].r >= l)
        {
            upd(p * 2 , l , r , k);
        }
        if(tree[p * 2 + 1].l <= r)
        {
            upd(p * 2 + 1 , l , r , k);
        }
        tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
        return;
    }
    inline int query(int p , int k)
    {
        if(tree[p].l == tree[p].r)
        {
            if(tree[p].sum <= k)
            {
                return tree[p].l;
            }
            return tree[p].l + 1;
        }
        if(tree[p].tag)
        {
            tree[p * 2].tag += tree[p].tag;
            tree[p * 2].sum += (tree[p * 2].r - tree[p * 2].l + 1) * tree[p].tag;
            tree[p * 2 + 1].tag += tree[p].tag;
            tree[p * 2 + 1].sum += (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1) * tree[p].tag;
            tree[p].tag = 0;
        }
        if(tree[p * 2 + 1].sum > k)
        {
            return query(p * 2 + 1 , k);
        }
        return query(p * 2 , k - tree[p * 2 + 1].sum);
    }
}xds;
signed main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    xds.build(1 , 1 , n);
    for(int i = 2 ; i <= n ; i++)
    {
        xds.upd(1 , 1 , i - 1 , a[i] - a[i - 1]);
        ans = max(ans , i - xds.query(1 , m) + 1);
    }
    cout << ans;
    return 0;
}
/*
0:16 读完 4 题题面
0:28 写完，大样例没过
0:29 hack: 5 4 0 1 1 1 2
0:32 调过
0:33 过大样例直接交
*/
