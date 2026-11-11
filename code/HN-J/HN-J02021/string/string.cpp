#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 10;

int n;
int a[N];
char c[N];
ll l, sum;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i] >> c[i];
    l += a[i];
  }
  int i = 1, j = n, l = a[n];
  char ch = c[n];
  for(; i < j; i++){
    while(a[i] > 0 && i < j){
      if(ch != c[i]){
        sum += min(l, a[i]);
      }
      int t = a[i];
      a[i] -= min(l, a[i]);
      l -= min(l, t);
      if(l == 0){
        if(i < j){
          l = a[--j], ch = c[j];
        }
      }
    }
  }
  cout << sum;
  return 0;
}

