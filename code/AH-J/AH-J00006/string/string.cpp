#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a[20005],n,sum = 0,z1 = 0,flag = 1,o = 1,ans = 0;
    char s[20005],ss[20005],l[20005],r[20005];
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i] >> s[i];
        sum += a[i];
    }
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= a[i];j++){
            ss[o] = s[i];
            o++;
        }
    }
    if (n <= 1){
        cout << "0";
        return 0;
    }
    if (sum % 2 == 1){
        z1 = (sum - 1) / 2;
        z1++;
        flag = 1;
    }
    else{
        z1 = sum / 2;
        flag = 0;
    }
    if (flag == 1){
        for (int i = 1;i <= z1 - 1;i++){
            l[z1 - i] = ss[i];
        }
        for (int i = z1 + 1;i <= sum;i++){
            r[i - z1] = ss[i];
        }
        for (int i = 1;i <= z1 - 1;i++){
            if (l[i] != r[i]) ans++;
        }
        cout << ans;
    }
    if (flag == 0){
        for (int i = 1;i <= z1;i++){
            l[z1 - i + 1] = ss[i];
        }
        for (int i = z1 + 1;i <= sum;i++){
            r[i - z1] = ss[i];
        }
        for (int i = 1;i <= z1;i++){
            if (l[i] != r[i]) ans++;
        }
        cout << ans;
    }
    return 0;
}
