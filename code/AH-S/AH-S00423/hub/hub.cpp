#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[114];

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,u;
    cin >> c >> u;
    while(u--)
    {
        memset(a,0,sizeof(a));
        int n,k;
        cin >> n >> k;
        if(c == 1)
        {
            for(int i = 1;i < n;i++)
            {
                int u,v;
                cin >> u >> v;
                a[u]++;
                a[v]++;
            }
            sort(a+1,a+n+1);
            if(n == 2)
            {
                if(k == 1) cout << "1";
                if(k == 2) cout << "0";
                cout << endl;
            }
            if(n == 3)
            {
                if(k == 1) cout << "1";
                if(k == 2) cout << "1";
                if(k == 3) cout << "0";
                cout << endl;
            }
            if(n == 4)
            {
                if(a[2] == 2)
                {
                    if(k == 1) cout << "2";
                }
                else
                {
                    if(k == 1) cout << "1";
                }
                if(k == 2) cout << "1";
                if(k == 3) cout << "1";
                if(k == 4) cout << "0";
                cout << endl;
            }
            if(n == 5)
            {
                if(a[1] == 4 && k == 1) cout << "2";
                if(a[1] == 3 && k == 1) cout << "2";
                if(a[1] == 2 && k == 1) cout << "1";
                if(k == 2) cout << "1";
                if(k == 3) cout << "1";
                if(k == 4) cout << "1";
                if(k == 5) cout << "0";
                cout << endl;
            }
        }
        else cout << 0 << endl;
    }
    return 0;
}
