#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 3e5 + 10;
struct Node {
	int first;
	char second;
};
int n, a[N], L, ans;
char c[N], c1[N];
vector <Node> b, q;
signed main() {
	
	
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i], a[i] += a[i - 1];
//	cout << 114514;
	if (a[n] % 2 == 0) {
//		cout << 114514;
	   int mid = a[n] / 2;
	   for (int i = 1; i <= n; i++) {
	   	   if (a[i - 1] <= mid && a[i] > mid) {
	   	      b.emplace_back (Node{a[i] - mid, c[i]});
	   	      if (mid - a[i - 1] > 0) q.emplace_back (Node {mid - a[i - 1], c[i]});
		   } 
		   else if (a[i] > mid && a[i - 1] > mid) b.emplace_back (Node {a[i] - a[i - 1], c[i]});
		   else q.emplace_back (Node{a[i] - a[i - 1], c[i]});
	   } 
//	   for (auto i : q) cout << i.first << ' ' << i.second << '\n';
//	   for (auto i : b) cout << i.first << ' ' << i.second << '\n';
       int j = 0; 
	   for (int i = q.size() - 1; i >= 0; i--) {
//	   	   cout << i << ' ' << j << '\n';
	   	   if (q[i].first >= b[j].first) 
	   	      while (q[i].first >= b[j].first && q[i].first) {
	   	       if (q[i].second != b[j].second) ans += b[j].first;
			   q[i].first -= b[j].first;
			   b[j].first = 0;
		 	   j++;	
//		 	   cout << i << ' ' << j << '\n';
		      }
		   if (q[i].first < b[j].first) {
		   	  if (q[i].second != b[j].second) ans += q[i].first;
			  b[j].first -= q[i].first;	
			  q[i].first = 0; 
		   }

	   }
	} else {
//		cout << 114514;
	    int mid = a[n] / 2 + 1;
	   for (int i = 1; i <= n; i++) {
	   	   if (a[i - 1] <= mid && a[i] >= mid) {
	   	      b.emplace_back (Node {a[i] - mid, c[i]});
	   	      if (mid - 1 - a[i - 1] > 0) q.emplace_back (Node {mid - 1 - a[i - 1], c[i]});
		   } 
		   else if (a[i] > mid && a[i - 1] > mid) b.emplace_back (Node {a[i] - a[i - 1], c[i]});
		   else q.emplace_back (Node {a[i] - a[i - 1], c[i]});
	   } 
//cout << 114514;
       int j = 0; 
	   for (int i = q.size() - 1; i >= 0; i--) {
     
		   if (q[i].first >= b[j].first) {
		   	  while (q[i].first >= b[j].first) {
	   	       if (q[i].second != b[j].second) ans += b[j].first;
			   q[i].first -= b[j].first;
			   b[j].first = 0;
			   if (b[j].first == q[i].first && b[j].first == 0) {
			   	  j++;
			   	  break;
			   }
		 	   j++;	
		      }
		   } 	 
		   if (q[i].first < b[j].first) {
		   	  if (q[i].second != b[j].second) ans += q[i].first;
			  b[j].first -= q[i].first;
			  q[i].first = 0;	 
		   }
		   
	   }
//	   cout << 114514;	
	}
	cout << ans;
	return 0;
} 
