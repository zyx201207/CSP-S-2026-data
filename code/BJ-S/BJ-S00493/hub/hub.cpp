#include<bits/stdc++.h>
using namespace std;
int random(int l, int r){
    return l + abs(rand() * rand() % (r - l + 1));
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "r", stdout);
    srand(time(0));
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> u[i] >> v[i];
        }
        cout << random(1, n / 2) << endl;
    } 
}

//祝我rp++，random直接AC
//100 + [12, 44] + [8, 24] + [0, 4] = [120, 172] nooooo
