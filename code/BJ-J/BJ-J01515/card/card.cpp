#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> a(n,0);
    vector<int> sum(m+1,0);
    for (int i = 0;i < n;++i){
        cin >>  a[i];
    }
    for (int i = 0;i < n;++i){
        vector<int> desk(n,0);
        vector<int> vis(m+1,-1);
        int pd = 0;
        for (int j = i;j < n;++j){
            if (vis[a[j]] == -1){
                desk[pd] = a[j];
                vis[a[j]] = pd++;
            }
            else{
                for (int p = vis[a[j]]+1;p < pd;p++){
                    vis[desk[p]] = -1;
                }
                pd = vis[a[j]]+1;
            }
        }
        for (int p = 0;p < pd;++p){
            sum[desk[p]]++;
        }
    }
    for (int i =1;i < m+1;++i){
        cout << sum[i] << ' ';
    }
    return 0;
}
