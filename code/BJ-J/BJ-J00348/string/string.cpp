#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long ans = 0;
    int n;
    cin >> n;
    vector<pair<int, char>>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    long long xi = 0, yi = 0;
    char xc, yc;
    for(int i=0, j=n-1; i<j;){
        if(xi == 0){
            xi += v[i].first;
            xc = v[i].second;
        }
        if(yi == 0){
            yi += v[j].first;
            yc = v[j].second;
        }
        if(xc == yc){
            if(xi > yi){
                xi -= yi;
                yi = 0;
                j--;
            }
            else if(xi < yi){
                yi -= xi;
                xi = 0;
                i++;
            }
            else{
                xi = 0;
                yi = 0;
                i++;
                j--;
            }

        }
        else{
            if(xi > yi){
                xi -= yi;
                ans += yi;
                yi = 0;
                j--;
            }
            else if(xi < yi){
                yi -= xi;
                ans += xi;
                xi = 0;
                i++;
            }
            else{
                ans += xi;
                xi = 0;
                yi = 0;
                i++;
                j--;
            }
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
