#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int a[N], t[N];

int main(){
   freopen("crystal.in", "r", stdin);
   freopen("crystal.out", "w", stdout);
   ios::sync_with_stdio(false);
   cin.tie(nullptr);


   long long n, m;
   cin >> n >> m;
   for(long long i = 1; i <= n; i++){
      cin >> a[i];
   }
   sort(a+1, a+n+1);

   int nn = n;
   int bn = 0;
   if(nn % 2 == 0){
      bn = nn / 2;
   }else{
      bn = nn / 2 + 1;
   }

   int cnt = 0;
   long long ii = 2;

   while(ii <= nn){
    if(a[ii] - a[ii-1] > m){
        cnt++;
        t[cnt] = ii - 1;
    }
    if(a[ii+1] - a[ii] > m){
        cnt++;
        t[cnt] = ii;
    }
    ii += 2;
   }


   if(cnt == 0){

    long long ccc = 0;
    for(int i = bn; i <= n; i++){
            long long xx = m, cc = 0;
        for(int j = n; j >= 1; j--){
            if(a[i] < a[j]){
                continue;
            }

            if(a[i] >= a[j]){
                xx -= a[i] - a[j];
                cc++;
            }

            if(xx <= 0){
                ccc = max(cc, ccc);
                break;
            }
        }


    }

    cout << ccc;
    return 0;
   }

   t[cnt + 1] = n;
   long long ans = 0;
   for(int i = 2; i <= cnt + 1; i++){
      long long anss = 0;
      for(int j = a[t[i+1]]; j >= a[t[i] + 1]; j--){
          long long x = m, c = 0;
          for(int k = a[t[i+1]]; k >= a[t[i] + 1]; k--){
              if(x > 0){
                if(a[j] >= a[k]){
                    x -= a[j] - a[k];
                    c++;
                }
              }else{
                break;
              }
          }
          anss = max(ans, c);
      }
      ans = max(ans, anss);
   }

   cout << ans;
   return 0;
}

