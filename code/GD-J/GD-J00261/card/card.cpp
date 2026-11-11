#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int b[300000];
int ans[300000];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n = 0, m;
    int a[500000], c[500000];

    int ans2 = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    //int c[500000];


    for (int i = 0; i < n; i++){
        int j = i;
        for (int l = i; j < n; j++, l++){
            if(b[a[l]] == 0){
                b[a[l]] = 1;
                c[j] = a[l];
            }
            else{
                j = i;
                for(;c[j] != a[l]; j++){
                }
            }


        }
        for (int aa = 0; aa < j; aa++)
            if (c[aa] == i){
                ans[ans2]++;
            }

    }

    for (int i = 0; i < n; i++)
        cout << ans[i];


    fclose(stdin);
    fclose(stdout);
    return 0;
}

