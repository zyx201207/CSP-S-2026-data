#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
pair<char,int> a[200005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].second;
        cin >> a[i].first;
    }
    int l=1,r=n;
    while(l < r){
        char lc = a[l].first,rc = a[r].first;
        int lnum = a[l].second,rnum = a[r].second;
        if(lnum < rnum){
            a[r].second -= a[l].second;
            if(lc!=rc)ans += a[l].second;
            l++;

        }
        if(lnum > rnum){
            a[l].second -= a[r].second;
            if(lc!=rc)ans += a[r].second;
            r--;

        }
        if(lnum == rnum){
            if(lc!=rc)ans += a[r].second;
            l++;
            r--;
        }

    }
    cout << ans;
    return 0;
}
