#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int a[n+10];
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }

    int b[m+10], end[m+10];
    for (int i=1;i<=m+10;i++){
        b[i]=0;
        end[i]=0;
    }

    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            b[a[j]]++;
            for (int z=1;z<=m+10;z++){
                if (b[z]>=2){
                    for (int x=1;z<=m+10;z++){
                        if (b[x]>=1){
                            b[x]--;
                        }
                    }
                }
            }
        for (int w=1;z<=m+10;z++){
            end[w]+=b[w];
        }
        }
    }
    for (int z=1;z<=m;z++){
        cout << end[z] <<" ";
    }

    return 0;
}
