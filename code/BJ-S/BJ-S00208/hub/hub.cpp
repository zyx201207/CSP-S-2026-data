#include<bits/stdc++.h>
using namespace std;

int u[1000010],v[100010];

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    cin >> c >> t;

    while(t--)
    {
        int n,k;
        cin >> n >> k;

        for(int i = 1;i < n;i++)
        {
            cin >> u[i] >> v[i];
        }

        if(k == 2)
        {
            bool fl1 = 1,fl2 = 1;
            for(int i = 2;i <= n;i++)
            {
                if(u[i] <= u[i - 1]) fl1 = 0;
                if(v[i] <= v[i - 1]) fl2 = 0;
            }

            if(!fl1 && !fl2)
            {
                cout << 1 << "\n";
                continue;
            }
        }

        cout << 2 << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
