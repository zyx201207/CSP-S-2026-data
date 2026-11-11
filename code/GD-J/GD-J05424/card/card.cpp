#include <bits/stdc++.h>
using namespace std;
int a[300005],b[300005] ={},cnt[300005] = {};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i= 1;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++){
        for (int j = i;j <= n;j++){
            for (int k = i;k < j;k++){
                if (b[k] == a[j]){
                    for (int l = k;l<j;l++){
                        b[l] = 0;
                    }
                    break;
                }
            }
            b[j] = a[j];
        }
        for (int j = i;j <= n;j++){
            cnt[b[j]]++;
			b[j] = 0;
        }
    }
    for (int i = 1;i <= m;i++){
        cout << cnt[i] << ' ';
    }
    return 0;
}
