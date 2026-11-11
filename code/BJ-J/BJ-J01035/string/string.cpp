#include <iostream>
#include <vector>
using namespace std;

int n, ans;
vector <char>  s;

int main () {
  freopen ("string.in", "r", stdin);
  freopen ("string.out", "w", stdout);
  cin >> n;
  for (int i=1;i<=n;i++) {
    int t;
    char c;
    cin >> t >> c;
    while (t--) {
    	s.push_back (c);
    	//cout << s[s.size()-1] << ' ';
    }
  }
  for (int i=0;i<(s.size()+1)>>1;i++) {
    if (s[i]!=s[s.size()-i-1]) {
    	//cout << i << s.size()-i-1 << endl;
    	ans++;
    }
  }
  cout << ans;
  return 0;
}