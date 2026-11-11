#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 5, M = 3 * 1e5 + 5;
int n, m, a[N];
struct Node {
  Node pre;
  Node next;
  int k;
};
Node desk[M];

int main() {
#ifndef LOCAL
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
#endif
  scanf("%d %d", &n, &m);
  srand(time(NULL));
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  for (int i = 1; i <= n; i++) {
    memset(desk, NULL, sizeof(desk));
    for (int j = i; j <= n; j++) {
      desk[1].pre = &desk[0];
      desk[1].next = &desk[2];
      desk[1].k = a[j];
    }
  }
  for (int i = 1; i <= m; i++) printf("%d", rand() % n);
  return 0;
}