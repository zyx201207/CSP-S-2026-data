#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int vis[3005];
vector<int> ve;
int ans[3005];
int ans1[3005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++)
    {
        ve.clear();
        for(int j=i; j<=n; j++)
        {
            bool flag = false;
            for(int k=0; k<ve.size(); k++)
            {
                if(ve[k] == a[j])
                {
                    flag = true;
                    break;
                }
            }
            if(flag == true) ve.clear();
            ve.push_back(a[j]);
            //for(int i=0; i<ve.size(); i++) cout << ve[i] << ' ';
            //cout << endl;
        }
        memset(ans1, 0, sizeof ans1);
        for(int j=0; j<ve.size(); j++)
        {
            ans1[ve[j]]++;
        }
        /*
        cout << endl;
        for(int i=1; i<=m; i++)
        {
            cout << ans1[i] << ' ';
        }
        cout << endl << endl;
        */
        for(int j=1; j<=m; j++)
        {
            if(ans1[j] != 0) ans[j]++;
        }
    }
    for(int i=1; i<=m; i++) cout << ans[i] << ' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
