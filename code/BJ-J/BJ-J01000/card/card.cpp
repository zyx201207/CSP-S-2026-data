#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int M = 3e5 + 5;
int n,m,a[maxn],ans[M],sum[M];

void find(int x,int b[maxn]){
    for(int i = x;i <= n;i++){
        int num = a[i];
        b[num]--;
        if(b[num] >= 1){
            //cout << x << ' ' << i << ' ' << num << ' ' << b[num] << ' ';
            i++;
            while(b[num] >= 1){
                b[a[i]]--;
                if(b[num] == 0)break;
                i++;
            }
            //cout << i <<endl;
        }
        ans[a[i]]++;
        //cout << x << ' ' << i << ' ' << a[i] << ' ' << ans[a[i]] << endl;
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum[a[i]]++;
    }
    for(int i = 1;i <= n;i++){
        int b[M];
        for(int j = 1;j <= m;j++){
            b[j] = sum[j];
        }
        find(i,b);
        /*
        for(int j = 1;j <= m;j++){
            cout <<ans[a[j]] << ' ';
        }
        cout << endl;
        for(int j = 1;j <= m;j++){
            cout <<sum[a[j]] << ' ';
        }
        cout << endl << endl;
        */
        sum[a[i]]--;
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
