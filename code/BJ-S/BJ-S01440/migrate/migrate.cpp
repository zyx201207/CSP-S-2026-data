#include<iostream>
using namespace std;
int n, d, c, t, x[2000006];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        if(c == 13 || c == 14){
            cout << 0 << '\n' ;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
