#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[500050],b[300050];
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    if(n == m){
        for(int i = 1;i <= m;i ++) cout << i;
        return 0;
    }
    for(int i = 1;i <= n;i ++){
        for(int j = i;j <= n;j ++){
            for(int k = j;k <= n;k ++){
                if(a[k] == a[j]){
                    j = k;
                }
            }
            b[a[j]] ++;
        }
    }
    for(int i = 1;i <= m;i ++){
        cout << b[i] << " ";
    }
    return 0;
}
