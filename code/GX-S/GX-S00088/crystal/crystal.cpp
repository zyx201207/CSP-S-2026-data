 #include <iostream>
 #include <algorithm>
 #include <queue>
 using namespace std;
 const int MAXN = 500050;
 int n,m,ans,a[MAXN],hs[MAXN],t[MAXN];
 int lowbit(int u)
 {
     return (u & (-u));
 }
 void add(int u,int val)
 {
     if (u == 0)
     {
         return;
     }
     for (int i = u;i <= n;i += lowbit(i))
     {
         t[i] += val;
     }
 }
 int query(int u)
 {
     if (u == 0)
     {
         return 0;
     }
     int sum = 0;
     for (int i = u;i >= 1;i -= lowbit(u))
     {
         sum += t[i];
     }
     return sum;
 }
 int main()
 {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    int minn = 0x3f3f3f3f3f;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        minn = min(a[i],minn);
    }
    if (minn < 0)
    {
        for (int i = 1;i <= n;i++)
        {
            a[i] -= minn;
        }
    }
    sort(a + 1,a + n + 1);
    deque <int> q;
    int sum = 0,top = a[0];
    for (int i = 1;i <= n;i++)
    {
        q.push_front(a[i]);
        add(a[i],1);
        int tmp = query(a[i] - 1) - query(q.back());
        sum += tmp * (a[i] - top);
        while ((sum > m) and (not q.empty()))
        {
            sum -= a[i] - q.back();
            q.pop_back();
        }
        ans = max(ans,(int)q.size());
        top = a[i];
    }
    cout << ans << endl;
    return 0;
 }
