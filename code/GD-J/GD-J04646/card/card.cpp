#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n+5];
    int cnt[m+2] = {0};
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        int l = i;
        while(l<n){
            if(l >= n) continue;
            int num = a[l];
            cnt[num]++;
            int ind = l;
            for(int j=n-1; j>l; j--){
                if(a[j] == num){
                ind = j;
                break;
                }
            }
            l = ind+1;
        }
    }
    for(int i=1; i<=m; i++) cout << cnt[i] << " ";
    return 0;
}
