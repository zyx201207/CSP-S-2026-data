#include <iostream>
#include <vector>
#include <unordered_set>

int a[500005], cnt[300005];
int n, m;

void game(int turn) {
  std::vector<int> cards;
  std::unordered_set<int> st;
  for (int i = turn; i <= n; i++) {
    if (st.count(a[i])) {
      while (cards.back() != a[i]) {
        st.erase(cards.back());
        cards.pop_back(); 
      }
      st.erase(a[i]);
      cards.pop_back(); 
    }
    cards.push_back(a[i]);
    st.insert(a[i]);
  }
  for (auto now : cards) std::cout << now << ' ', cnt[now]++;
  std::cout << '\n';
  return;
}

int main() {
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) game(n);
  for (int i = 1; i <= m; i++) std::cout << cnt[i] << ' ';
  return 0;
}
