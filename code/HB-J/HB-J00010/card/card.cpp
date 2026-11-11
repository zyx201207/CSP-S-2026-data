#include <bits/stdc++.h>
using namespace std;
char a[500010];
int main(){
    freopen("card.in","r" ,stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int x = 0,y = 0,z = 0;
    while(n--){
        cin >> a[n];
        if(a[n] == 1){
            x++;
            }
            if(a[n] == 2){
                y++;
            }
            if(a[n] == 3){
                z++;
            }
        }
        cout << x << y << z;
    return 0;
}
