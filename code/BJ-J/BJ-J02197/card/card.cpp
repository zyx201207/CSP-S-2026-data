#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n, m;
    cin >> n >> m;
    int a[n], b[m+1] = {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        int c[m+1] = {0};
        int cnt = i;
        for(int j = n - 1; j >= i; j--){
            if(c[a[j]] == 1){
                cnt = j;
                break;
            }
            c[a[j]]++;
        }
        for(int j = cnt; j < n; j++){
            b[a[j]]++;
        }
    }
    for(int i = 1; i < m + 1; i++){
        cout << b[i] << " ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}