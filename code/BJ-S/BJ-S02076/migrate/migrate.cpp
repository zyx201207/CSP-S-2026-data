#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
typedef long long ll;

int Data, T, n;
ll d, a[N], len[N], ways[N], ans, sum;

void print0(int id){
    for(int i=id+1; i<=n; i++)
        cout << len[i] << ' ';
    cout << '\n';
}

void print(int id){
    for(int i=id+1; i<=n; i++)
        cout << ways[i] << ' ';
    cout << '\n';
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> Data >> T;
    while(T--){
        cin >> n >> d;
        for(int i=1; i<=n; i++)
            cin >> a[i];

        ans = 0;
        for(int i=1; i<=n; i++){
            // start from i
            memset(len, 0, sizeof(len));
            memset(ways, 0, sizeof(ways));
            int j = i;
            while(j <= n){
                int k = n+1; a[n+1] = LONG_LONG_MAX;
                for(; k>j; k--){
                    if(a[j]+d >= a[k]){
                        len[k] = len[j] + 1;
                        break;
                    }
                }
                if(k == j) break;
                j = k;
                if(j == n) break;
            }
            for(j=n; j>i; j--)
                if(!len[j]) len[j] = len[j+1];

            // cout << "Now print [len]\n";
            // print0(i);

            len[i] = 0, ways[i] = 1;
            for(int j=i+1; j<=n; j++){
                int k = j-1;
                while(k >= i && a[k] + d >= a[j]){
                    if(len[k] + 1 == len[j])
                        ways[j] += ways[k];
                    k--;
                }
                if(ways[j] == 2) ans++;
            }

            // cout << "Now print [ways]\n";
            // print(i);


        }
        cout << ans << '\n';
    }

    return 0;
}
