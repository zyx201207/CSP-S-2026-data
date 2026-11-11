#include <bits/stdc++.h>
using namespace std;
long long a[1000005],c[1000005],s[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(long long i = 1;i <= n;i++) cin >> a[i];
    for(long long p = 1;p <= n;p++){
        for(long long i = 1;i <= n;i++) s[i] = 0;
        for(long long i = p;i <= n;i++){
            for(long long j = 1;j < i;j++){
                if(s[j] == a[i]){
                    for(int k = j;k < i;k++) s[k]=-1;
                }
            }
            s[i] = a[i];
        }
        for(long long i = 1;i <= n;i++)
            if(s[i] != -1) c[s[i]]++;
    }
    for(long long i = 1;i <= m;i++) cout << c[i] << " ";
    return 0;
}
