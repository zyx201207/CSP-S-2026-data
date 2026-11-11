#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans,s[300005],l,r;
int k[500005],g[500005];
stack <int> t;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        l = 1;
        r = i;
        while (l <= r)
        {
            if (a[l] == a[r])
            {
                for (int j = l+1;j < r;j++)
                {
                    k[a[j]]++;
                }
                g[l] = 0x3f3f3f3f;
                g[r] = 0x3f3f3f3f;
            }
            l++;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        s[a[i]]+=i;
    }
    for (int i = 1;i <= n;i++)
    {
        if (k[a[i]]!=0)
        {
            s[a[i]]-=k[a[i]];
        }
    }
    for (int i = 1;i <= m;i++)
    {
        cout << s[i] << endl;
    }
}
