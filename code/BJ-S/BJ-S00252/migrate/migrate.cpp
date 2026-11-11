#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
long long a[N];
long long c,t,n,d;
long long f[N][N];
vector<int>vec[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            scanf("%lld",&a[i]);
            vec[i].clear();
        }
        int lst = 1;
        int ans = 0;
        for(int i = 2;i <= n;i++){
            while(lst < i && a[lst] + d < a[i]){
                lst++;
            }

            for(int j = lst;j < i;j++){
                vec[i].push_back(j);
            }
        }
        int tot = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                long long p = a[i];
                bool flag = 0;int mina = 0,r = i;
                int ls = -1;
                while(p < a[j]){
                    p += d;
                    mina++;
                    while(r + 1 <= n && a[r + 1] <= p){r++;}
                    if(r == ls){
                        flag = 1;
                        break;
                    }
                    p = a[r];
                    ls = r;
                }
                if(flag){break;}

                for(int k = i - 1;k <= j;k++){
                    for(int l = 0;l <= mina;l++){
                        f[k][l] = 0;
                    }
                }f[i][0] = 1;
                for(int k = i + 1;k <= j;k++){
                    for(int l = 1;l <= mina;l++){
                        for(int u : vec[k]){
                            if(u < i){continue;}
                            f[k][l] += f[u][l - 1];
                            if(f[k][l] > 2){
                                f[k][l] = 3;
                            }
                        }
                    }
                }
                if(f[j][mina] == 2){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }

}
