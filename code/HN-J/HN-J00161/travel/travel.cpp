#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
#define lll __int128
#define ve vector<int>
#define vel vector<ll>
#define veve vector<ve>
#define veb vector<bool>
#define pb push_back
#define pob pop_back

using namespace std;

const int inf = 1e9;
int a, b, c, d, cnt;
char q, p;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> q >> c >> d >> p;
    if(q == 'F'){
        q --;
    }
    if(p == 'F'){
        p --;
    }
    if(a != c){
        cout << "0000";
        AC;
    }
    if(b != d){
        cout << "1000";
        AC;
    }
    if(q <= 'C' && p  > 'C' || q > 'C' && p <= 'C'){
        cout << "1100";
        AC;
    }
    if(abs(q - p) == 1){
        cout << "1111";
    }else{
        cout << "1110";
    }
    AC;
}
