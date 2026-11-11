#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

vector<bool> vis;
vector<int> cards,cnt;
deque<int> deck,line;

void init_deck(const int& addFrom,const int& addTo) {
    for (int i = addFrom; i <= addTo; i++) {
        deck.push_back(cards[i]);
    }
}

void countLeft(const int& maxNumber) {
    for (int i = 1; i <= maxNumber; i++) {
        cnt[i] += vis[i];
    }
}

int main(int argc,char* argv[]) {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin >> n >> m;
    vis.resize(m + 1);
    cnt.resize(m + 1);
    cards.resize(1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cards.push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        init_deck(i,n);

        while (!deck.empty()) {
            int th = deck.front();
            if (!vis[th]) {
                vis[th] = 1;
                deck.pop_front();
                line.push_back(th);
            }

            else {
                while (line.back() != th) {
                    vis[line.back()] = 0;
                    line.pop_back();
                }

                // When the 'line' reaches 'th', the loop will be paused.
                // So 'th' won't be deleted, we needn't add it again.
                vis[th] = 1;
                deck.pop_front();
            }
        }

        countLeft(m);
        vis.clear();
        vis.resize(m + 1);
    }

    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }

    // This solution cannot get 100 but it can get 16.
    // I think I am so amazing because I can get scores from the question 4.

    return EXIT_SUCCESS;
}

// O(n^3)
// get about 16
