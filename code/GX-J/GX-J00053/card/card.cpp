#include <bits/stdc++.h>
using namespace std;
long long num[500005];
long long ti[300005],id[300005];
int main ()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> num[i];
    }
    bool ok = 0;
    for (int i = n;i >= 1;i--){
        /*if(!ok){
            for (int j = i + 1;j <= n;j++){
                if (num[j] == num[i]){
                    for (int k = i+1;k<= j;k++){

                    }
                    ok = 1;
                    break;
                }
            }
        }
        else{
            ok = 0;
        }
        if (ok){
            i++;
            continue;
        }*/
        if (id[num[i]]){
            for (int j = i + 1;j < id[num[i]];j++){
                id[num[j]] = 0;
            }
        }
        id[num[i]] = i;
        for (int j = 1;j <= m;j++){
            if (id[j]){
                ti[j] ++;
            }
        }
    }
    for (int i = 1;i <= m;i++){
        cout<< ti[i] << ' ';
    }
    return 0;
}
