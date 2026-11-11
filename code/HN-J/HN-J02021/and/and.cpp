#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, lenm;
string s[N];

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1, x; i <= n; i++){
    cin >> x;
    while(x){
      s[i] += x % 2 + '0';
      x /= 2;
    }
    lenm = max(lenm, (int)s[i].size());
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1, sz = s[i].size(); j <= lenm - sz; j++){
      s[i] += '0';
    }
    reverse(s[i].begin(), s[i].end());
  }
  long long sum = 0;
  vector<int> pos, t;
  for(int i = 1; i <= n; i++){
    pos.push_back(i);
  }
  for(int i = 0; i < lenm; i++){
    for(int j : pos){
      if(s[j][i] == '1'){
        t.push_back(j);
      }
    }
    if(t.size() >= m){
      sum += (1 << (lenm - i - 1));
      pos = t;
    }
    t.clear();
  }
  cout << sum;
  return 0;
}
/*
11111
00001
00111
00011
01111
*/
