#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int a[500005], ma[300005];
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int turn=1; turn<=n; turn++){
        int mp[3005] = {0};
        vector<int> cards(0);
        for(int i=turn; i<=n; i++){
            if(mp[a[i]]+1 >= 2){
                for(int i=0; i<=m; i++) mp[i] = 0;
                cards = {0};
            }
            mp[a[i]]++;
            cards.push_back(a[i]);
        }
        for(int i=0; i<cards.size(); i++) ma[cards[i]]++;

    }

    for(int i=1; i<=m; i++) cout << ma[i] << ' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
