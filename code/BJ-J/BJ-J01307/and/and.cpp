#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(m == 1){
        long long maxn = 0;
        for(int i = 1;i <= n;i++)
            maxn = max(maxn,a[i]);
        cout << maxn;
    }
    else if(m == 2){
        long long maxn = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                maxn = max(maxn,a[i]&a[j]);
        cout << maxn;
    }
    else if(m == 3){
        long long maxn = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                for(int k = j+1;k <= n;k++)
                    maxn = max(maxn,a[i]&a[j]&a[k]);
        cout << maxn;

    }
    else if(m == 4){
        long long maxn = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                for(int k = j+1;k <= n;k++)
                    for(int l = k+1;l <= n;l++)
                        maxn = max(maxn,a[i]&a[j]&a[l]&a[k]);
        cout << maxn;
    }
    else if(m == 5){
        long long maxn = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                for(int k = j+1;k <= n;k++)
                    for(int l = k+1;l <= n;l++)
                        for(int o = l+1;o <= n;o++)
                            maxn = max(maxn,a[i]&a[j]&a[k]&a[l]&a[o]);
        cout << maxn;
    }
    else if(m == 6){
        long long maxn = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                for(int k = j+1;k <= n;k++)
                    for(int l = k+1;l <= n;l++)
                        for(int o = l+1;o <= n;o++)
                            for(int p = o+1;p <= n;p++)
                                maxn = max(maxn,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]);
        cout << maxn;
    }
    else if(m == 7){
        long long maxn = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                for(int k = j+1;k <= n;k++)
                    for(int l = k+1;l <= n;l++)
                        for(int o = l+1;o <= n;o++)
                            for(int p = o+1;p <= n;p++)
                                for(int q = p+1;q <= n;q++)
                                    maxn = max(maxn,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]);
        cout << maxn;
    }
    else if(m == 8){
        long long maxn = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                for(int k = j+1;k <= n;k++)
                    for(int l = k+1;l <= n;l++)
                        for(int o = l+1;o <= n;o++)
                            for(int p = o+1;p <= n;p++)
                                for(int q = p+1;q <= n;q++)
                                    for(int r = q+1;r <= n;r++)
                                        maxn = max(maxn,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]);
        cout << maxn;
    }
    else if(m == 9){
        long long maxn = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                for(int k = j+1;k <= n;k++)
                    for(int l = k+1;l <= n;l++)
                        for(int o = l+1;o <= n;o++)
                            for(int p = o+1;p <= n;p++)
                                for(int q = p+1;q <= n;q++)
                                    for(int r = q+1;r <= n;r++)
                                        for(int s = r+1;s <= n;s++)
                                            maxn = max(maxn,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]);
        cout << maxn;
    }
    else if(m == 10){
        long long maxn = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                for(int k = j+1;k <= n;k++)
                    for(int l = k+1;l <= n;l++)
                        for(int o = l+1;o <= n;o++)
                            for(int p = o+1;p <= n;p++)
                                for(int q = p+1;q <= n;q++)
                                    for(int r = q+1;r <= n;r++)
                                        for(int s = r+1;s <= n;s++)
                                            for(int t = s+1;t <= n;t++)
                                                maxn = max(maxn,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]);
        cout << maxn;
    }
    return 0;
}
