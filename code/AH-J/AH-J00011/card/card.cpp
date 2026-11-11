#include <bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];
int c[100005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int x = 0;
    for(int i = 1;i <= n;i ++){
        x++;
        cin >> a[i];
        c[i] = a[i];
    }
    int y = 2;
    for(int i = 1;i<=n;i++){
        for(int l =1;l <= x;l ++){
            if(a[i] == a[l]){
                for(int k = l;k > 0;k --){
                    a[k] = 0;
                }
            }
        }
        for(int j = 1;j <= n;j ++){
           if(a[i] = j){
                b[j] ++;
            }
        }
        for(int g = y;g<=n;g++){
            a[x+1] = c[g];
            x++;
        }
        y ++;
    }
    for(int i = 1;i <= m;i ++){
        cout << b[i] << " ";
    }
    return 0;
}
