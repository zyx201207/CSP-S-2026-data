#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int f  = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == a[1]){
                f++;
            }
        }
        cout << f;
        f == 0;
    }
    return 0;
}
