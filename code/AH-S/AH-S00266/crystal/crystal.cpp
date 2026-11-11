#include <bits/stdc++.h>
using namespace std;

int n ,maxans = 0;
long long m ,a[500005];
map <long long ,int> mp;
vector <long long> v;

int main ()
{
    freopen ("crystal.in","r" ,stdin);
    freopen ("crystal.out" ,"w" ,stdout);
    //printf ("print:");
    scanf ("%d%lld" ,&n ,&m);
    for (int i = 1;i <= n;i++)
    {
        scanf ("%lld" ,&a[i]);
        mp[a[i]]++;
    }
    /*
    for (auto it : mp)
    {
        printf ("%lld%d\n" ,it.first ,it.second);
    }
    */
    //long long lused = 0;
    //int lans = 0;
    for (auto it : mp)
    {
        long long vi = it.first ,la = m;
        int ans = mp[vi];
        v.push_back(vi);
        //printf ("%d\t" ,v.size());
        for (int i = v.size() - 2;i >= 0;i--)
        {
            //printf ("%d  " ,mp[v[i]]);
            long long ne = vi - v[i] ,js = ne * mp[v[i]];
            //printf ("%lld %lld  " ,ne ,js);
            la -= js;
            //printf ("%d        " ,la);
            ans += mp[v[i]];
            if (la < 0)
            {
                long long hf = abs(la - ne + 1) / ne;
                //printf ("%d  " ,hf);
                ans -= hf;
                break;
            }
            if (la == 0) break;
        }
        //printf ("%d\n" ,ans);
        maxans = max(maxans ,ans);
    }
    //printf ("%d %d\n" ,v.size() ,mp.size());
    printf ("%d\n" ,maxans);
    //printf ("%d\n" ,clock());
    return 0;
}
