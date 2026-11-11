#include <bits/stdc++.h>

using namespace std;
long long n,a[200100],ans = 0;
char b[200100];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
        cin >> b[i];
    }
    for(int i = 1,j = n;i < j;){
            if(b[i] != b[j]){
               if(a[i] > a[j]){
                a[i] -= a[j];
                ans += a[j];
                j--;
            }else if(a[i] < a[j]){
                a[j] -= a[i];
                ans += a[i];
                i++;
            }else{
               ans += a[i];
               i++;
               j--;
            }
        }else{
               if(a[i] > a[j]){
                a[i] -= a[j];
                j--;
            }else if(a[i] < a[j]){
                a[j] -= a[i];
                i++;
            }else{
               i++;
               j--;
            }
       }
    }
    cout << ans;
    return 0;
}
