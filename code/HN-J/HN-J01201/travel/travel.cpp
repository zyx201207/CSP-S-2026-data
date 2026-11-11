#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string c1, s1, c2, s2;
ll a[10];

int main(){
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> c1 >> s1 >> c2 >> s2;
  if(c1 == c2){
    a[1] = 1;
    if(s1[0] == s2[0] && s1[1] == s2[1]){
      a[2] = 1;
      if(!((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C'))){
        a[3] = 1;
        if(abs(int(s2[2] - s1[2])) == 1){
          a[4] = 1;
        }
      }
    }
  }
  for(int i = 1; i <= 4; i++){
    cout << a[i];
  }
  return 0;
}
