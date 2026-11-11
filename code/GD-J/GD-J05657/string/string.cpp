#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n;
int cnt[N];
char type[N];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> cnt[i];
        cin >> type[i];
    } 
    int l = 1, r = n, lstl = cnt[1], lstr = cnt[n];
    char typel = type[1], typer = type[n];
    long long ans = 0;
    while(l < r){
        int nwcnt = min(lstl, lstr);
        if(typel != typer)ans += nwcnt;
        lstl -= nwcnt;
        lstr -= nwcnt;
        if(lstl == 0)l++, lstl += cnt[l], typel = type[l];
        if(lstr == 0)r--, lstr += cnt[r], typer = type[r];
    }
    cout << ans;
    return 0;
}
