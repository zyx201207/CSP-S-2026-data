#include <bits/stdc++.h>
using namespace std;
long long n, l = 0;
long long cnt = 0;
struct zz {
    int x;
    char y;
};
vector <zz> v;

int main (){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++){
        int ll; char ls;
        cin >> ll >> ls;
        v.push_back({ll, ls});
    }
    //for (auto i : v) cout << i.x << " " << i.y << "\n";
    long long g = 0, h = n - 1;
    while (g < h){
        int Min = min(v[g].x, v[h].x);
        if (v[g].y != v[h].y) cnt += Min;
        v[g].x -= Min;
        v[h].x -= Min;
        //cout << g << " " << h << "\n";
        if (v[g].x <= 0) g++;
        if (v[h].x <= 0) h--;
    }
    //cout << g << h;
    cout << cnt;
    return 0;
}

