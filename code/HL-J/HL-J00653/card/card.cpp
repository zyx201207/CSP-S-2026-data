#include <bits/stdc++.h>
using namespace std;
int n, m, p = 1;
int a[500005], sum[500005];
long long ans[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            for(int k = 0; k <= p; k++){
                if(sum[k] == a[j]){
                    for(int l = k; l <= p; l++)
                        sum[l] = 0;
                    p = k-1;
                }
            }
            sum[p++] = a[j];
        }
        for(int j = 0; j <= p-1; j++)
            ans[sum[j]]++;
    }
    for(int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
	return 0;
}
