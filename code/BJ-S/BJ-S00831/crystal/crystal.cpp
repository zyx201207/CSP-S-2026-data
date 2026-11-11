#include<bits/stdc++.h>
using namespace std;
const int N = 1e9;
long long s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,sum = 0,cnt = 1;
    cin >> n >> m;

    for(int i = 1;i <= n;i++) cin >> s[i];
    for(int i = 1;i <= n;i++){
        if(cnt){
            if(i + 1  < n){
                if(s[i] != s[i+1]){
                    while(1){
                        s[i]++;
                        m--;
                        if(s[i] == s[i + 1]){
                            break;
                        }
                        if(s[i] == s[i + 1]){
                            break;
                        }
                }
                }else if(s[i] == s[i + 1]){
                    continue;
                }
                for(int j = 1;j <= i;j++){
                    if(s[j] != s[i+1]){
                        while(1){
                        s[i]++;
                        m--;
                        if(s[i] == s[i + 1]){
                            break;
                        }
                        if (m == 0){
                            cnt == 0;
                            break;
                        }
                    }
                }

            }
        }
    }
    }
    for(int i = 1;i <= n;i++){
        if(s[1] == s[i]){
            sum++;
        }
    }
    cout << sum;
    return 0;
    }
