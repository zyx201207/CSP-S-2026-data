#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> a(n), cnt(m+1, 0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        vector<int> b, tcnt(m+1, 0), pos(m+1, 0);
        for(int j=i;j<n;j++){
            int cur = a[j];
            if(tcnt[a[j]] == 0){
                b.push_back(a[j]); tcnt[a[j]] = 1; pos[a[j]] = b.size()-1;
            }else{
                for(int k=0;k<b.size() - pos[a[j]];k++){
                    tcnt[b[b.size()-1]] = 0;
                    b.pop_back();
                }
                b.push_back(a[j]); tcnt[a[j]] = 1; pos[a[j]] = b.size()-1;
            }

        }
        for(int j=1;j<=m;j++) cnt[j] += tcnt[j];

    }
    for(int i=1;i<=m;i++){
        cout << cnt[i] << " ";
    }
    return 0;

}
