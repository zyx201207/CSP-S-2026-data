#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin >> n >> m;
    int card[n];
    for (int i = 0;i < n;i++){
        cin >> card[i];
    }
    //zhonglei
    int x[m];
    int mj = 0;
    for(int i = 0;i < n;i++){
        int xm = 0;
        for(int j = 0;j < i;j++){
            if (x[j] == card[i]){
                xm = 1;
                break;
            }
        }
        if(xm == 0){
            x[mj] = card[i];
            mj++;
        }
    }
    sort(x[1],x[m]);

    int h[m];
    for (int i = 0;i < m;i++){
        int card_xh[m];
        for(int j = i;j < m;j++){
            int k = card[j];
            for (int p = 0;p < m;p++){
                if (card_xh[p] == k){
                    for(int f = p;f < m;f++){
                        card_xh[p] == 0;
                    }
                    card_xh[p] = k;
                    k++;
                    break;
                }
            }
            if(k == card[j]){
                card_xh[j-i] = k;
            }
        }
        for(int j = 0;j < m-i;j++){
            if(card_xh[j] != 0){
                int a = card_xh[j];
                h[a] = h[a] + 1;
            }else{
                break;
            }
        }
    }

    for(int i = 0;i < n;i++){
        int l = x[i];
        cout << h[l] << " ";
    }


    return 0;
}

