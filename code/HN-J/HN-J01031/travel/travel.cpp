#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 256 + 10;
int ch[M][M];
string c1, s1, c2, s2;
void init(){
  ch['A']['B'] = 1, ch['B']['A'] = 1;
  ch['A']['C'] = 1, ch['C']['A'] = 1;
  ch['B']['C'] = 1, ch['C']['B'] = 1;
  ch['F']['D'] = 1, ch['D']['F'] = 1;
}
int main(){
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  cin >> c1 >> s1 >> c2 >> s2;
  init();
  cout << (c1 == c2);
  if(c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2)){
    cout << 1;
  }
  else{
    cout << 0;
  }
  if(c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2) && ch[s1[2]][s2[2]]){
    cout << 1;
  }
  else{
    cout << 0;
  }
  if(c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2) && ch[s1[2]][s2[2]]&& abs(s1[2] - s2[2]) == 1){
    cout << 1;
  }
  else{
    cout << 0;
  }
  return 0;
}
