#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 2e6;
int a[N + 5],n,d;
int l[N + 5],r[N + 5];

void solve1()
{
    d /= a[2] - a[1];
    if(d == 0)
    {
        cout <<0 <<endl;
        return ;
    }
    if(d == 1)
    {
        cout << 0 << endl;
        return ;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(i + d * 2 > n + 1) break;
        ans++;
    }
    cout << ans << endl;
    return ;
}
void solve2()
{
    int p = 1;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] - a[1] <= d) p = i;
        else break;
    }
    l[1] = p;
    for(int i = 2;i <= n;i++)
    {
        while(p < n && a[p + 1] - a[i] <= d)
        {
            p++;
        }
        l[i] = p;
    }
    //for(int i = 1;i <= n;i++) cout << l[i] << ' ';
    //cout <<endl;
    p = n;
    for(int i = n;i >= 1;i--)
    {
        if(a[n] - a[i] <= d) p = i;
        else break;
    }
    r[n] = p;
    for(int i = n - 1;i >= 1;i--)
    {
        while(p > 1 && a[i] - a[p - 1] <= d)
        {
            p--;
        }
        r[i] = p;
    }
    //for(int i = 1;i <= n;i++) cout << r[i] << ' ';
    //cout <<endl;
    int pos = 0;
    for(int i = 1;i <= n;i++)
    {
        if(l[i] == n && r[i] == 1)
        {
            pos = i;
            break;
        }
    }
    //cout << pos << endl;
    int t1 = 0,t2 = 0;
    for(int i = n;i > pos;i--)
    {
        //cout <<r[i] << ' ';
        if(r[i] <= pos - 2) break;
        if(r[i] == pos) t2++;
        else t1++;
    }
    //cout << t1 << ' ' << t2 <<endl;
    int ans = 0;
    for(int i = 1;i < pos;i++)
    {
        if(l[i] >= pos + 2) break;
        if(l[i] == pos)
        {
            ans += t1;
        }
        else
        {
            ans += t2;
        }
    }
    cout << ans << endl;
    return ;
}
void solve3()
{
    int p = 1;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] - a[1] <= d) p = i;
        else break;
    }
    l[1] = p;
    for(int i = 2;i <= n;i++)
    {
        while(p < n && a[p + 1] - a[i] <= d)
        {
            p++;
        }
        l[i] = p;
    }
    //for(int i = 1;i <= n;i++) cout << l[i] << ' ';
    //cout <<endl;
    p = n;
    for(int i = n;i >= 1;i--)
    {
        if(a[n] - a[i] <= d) p = i;
        else break;
    }
    r[n] = p;
    for(int i = n - 1;i >= 1;i--)
    {
        while(p > 1 && a[i] - a[p - 1] <= d)
        {
            p--;
        }
        r[i] = p;
    }
    //for(int i = 1;i <= n;i++) cout << r[i] << ' ';
    //cout <<endl;
    int ans = 0,res = 0;
    p = 1;
    int hd = 2,tl = l[1];
    //cout << p << ' ' << hd << ' ' <<tl <<endl;
    while(hd < n)
    {
        if(hd > tl) break;
        if(hd == tl)
        {
            p = tl;
            hd = tl + 1;
            tl = l[p];
        //cout << p << ' ' << hd << ' ' << tl <<endl;
            continue;
        }
        int t1 = l[tl],t2 = l[tl - 1],t3 = l[tl - 2];
        p = tl;
        res += t2 - t3;
        tl = t1;
        hd = t2 + 1;
        //cout << p << ' ' << hd << ' ' << tl <<endl;
    }
    //cout << res << endl;
    ans += res;
    for(int i = 2;i <= n;i++)
    {
        res = 0;
        p = i;
        bool f = 0;
        int poss;
        int hd = i + 1,tl = l[i];
        int tt1,tt2,tt3,pp;
        //cout << i << ':';
        //cout << p << ' ' << hd << ' ' <<tl <<endl;
        while(hd < n)
        {
            if(hd > tl) break;
            if(hd == tl)
            {
                p = tl;
                hd = tl + 1;
                tl = l[p];
                continue;
            }
            int t1 = l[tl],t2 = l[tl - 1],t3 = l[tl - 2];
            p = tl;
            if(t2 - t3 > 0 && t2 + 1 > t1)
            {
                pp = p;
                tt1 = t1;
                tt2 = t2;
                tt3 = t3;
                f = 1;
            }
            res += t2 - t3;
            tl = t1;
            hd = t2 + 1;
            //cout << p << ' ' << hd << ' ' << tl <<endl;
        }/*
        if(f)
        {
            p = pp;
            hd = tt3 + 1;
            tl = tt2;
            while(hd < n)
            {

            }
        }*/
        //cout << res << endl;
        ans += res;
    }
    cout << ans << endl;
    return ;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin >> c >> T;
	while(T--)
    {
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        if(11 <= c && c <= 12) solve1();
        if(13 <= c && c <= 14) solve2();
        solve3();
    }
	return 0;
}
