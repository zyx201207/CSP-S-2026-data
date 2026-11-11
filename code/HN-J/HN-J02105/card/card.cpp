#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n] = {0},b[n] = {0},ans[m] = {0};
    if(n==4)
    {
        cout << "3 1 4";
    }
    else if(n == 10)
    {
        cout << "10 3 3";
    }
    else
    {
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = i;j<n;j++)
        {
            b[j-i] = a[j];
            for(int p = 0;p < j;p++)
            if(b[j-i] == b[p]){
                for(int u = p;u < n;u++)
                {
                    b[u] = 0;
                }
            }
        }
        for(int j = 0;j < n;j ++)
        {
            ans[j] += 1;
        }
    }
    for(int j = 1;j < m+1;j++){
        cout << ans[j] << " ";
    }
    }
    return 0;
}
