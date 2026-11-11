#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
using ll = long long;

ll n;

struct node1{
  ll x;
  char c;
}a[N], b[N];

stack <node1> q;

int main(){
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;
  ll sum = 0;
  for(int i = 1; i <= n; i++){
    cin >> b[i].x >> b[i].c;
    sum += b[i].x;
  }
  ll cnt = 0, l = 0, e = 0, p = 0;
  for(int i = 1; i <= n; i++){
    if(cnt + b[i].x <= sum / 2 || e == 1){
      l++;
      a[l] = b[i];
      cnt += b[i].x;
    }else{
      ll o = sum / 2 - cnt;
      l++;
      p = l;
      a[l].x = o, a[l].c = b[i].c;
      l++;
      a[l].x = b[i].x - o; a[l].c = b[i].c;
      e = 1;
      cnt += b[i].x;
    }
  }
  /*
  for(int i = 1; i <= l; i++){
    cout << a[i].x << ' ' << a[i].c << '\n';
  }
  cout << p;
  return 0;
  */
  for(int i = p + 1; i <= l; i++){
    q.push({a[i].x, a[i].c});
  }
  ll ans = 0;
  for(int i = 1; i <= p; i++){
    ll cnt = a[i].x, c = a[i].c;
    while(!q.empty()){
      node1 k = q.top();
      q.pop();
      if(cnt >= k.x){
        if(c != k.c){
          ans += k.x;
        }
        cnt -= k.x;
      }else if(cnt > 0){
        if(k.c != c){
          ans += cnt;
        }
        k.x -= cnt;
        cnt = 0;
        q.push({k.x, k.c});
      }else{
        q.push({k.x, k.c});
        break;
      }
    }
  }
  cout << ans;
  return 0;
}

/*

2
2 a
3 a

3
2 a
2 b
1 c

4
1 a
2 b
1 b
10 a

*/
