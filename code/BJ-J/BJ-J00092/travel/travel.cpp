#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn];
string nx, ny, mx, my;

void solve(){
    cin >> nx >> ny >> mx >> my;
    if(nx[0] == mx[0] && nx[1] == mx[1])
    {
        cout << "1";
        if(ny[0] == my[0] && ny[1] == my[1])
        {
            cout << "1";
            if((ny[2] >= 'A' && ny[2] <= 'C' && my[2] >= 'A' && my[2] <= 'C') || (ny[2] == 'D' || ny[2] == 'F' && my[2] == 'D' || my[2] == 'F'))
            {
                cout << "1";
                if(ny[2] == 'A' && my[2] == 'B' || ny[2] == 'B' && my[2] == 'A' || ny[2] == 'C' && my[2] == 'B' || ny[2] == 'B' && my[2] == 'C' || ny[2] == 'D' && my[2] == 'F' || ny[2] == 'F' && my[2] == 'D')
                {
                    cout << "1";
                }
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}
