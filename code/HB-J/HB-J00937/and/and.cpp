#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];
int maxl = -1;
string num[200005];

string tb(int x){
    string re = "";

    while(x > 0){
        re += (char)(x % 2 + '0');
        x /= 2;
    }

    string tre = re;
    for(int i = re.size() - 1; i >= 0; i--){
        tre[i] = re[re.size() - 1 - i];
    }

    return tre;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        num[i] = tb(a[i]);
        //cout << num[i] << endl;

        if((int)num[i].size() >= maxl){
            maxl = num[i].size();
        }
    }

    for(int i = 1; i <= n; i++){
        int nowsize = (int)num[i].size();

        for(int j = 1; j <= maxl - nowsize; j++){
            num[i] = '0' + num[i];
        }
    }

    sort(num + 1, num + n + 1);

    string ans = num[1];

    for(int i = 0; i < maxl; i++){
        int nowand = 1;
        for(int j = n; j > n - m ; j--){
            nowand *= num[j][i] - '0';

        }
        ans[i] = (char)nowand + '0';
    }

    int sum = 0;

    int anslen = ans.size();

    int cnt = 1;
    for(int i = 0; i < anslen; i++){
        //cout << (int)(ans[anslen - 1 - i] - '0') * pow(2,i)<< endl;
        sum += (int)(ans[anslen - 1 - i] - '0') * pow(2,i);
        //cout << sum << endl;
    }

    cout << sum;


    return 0;
} // 4 2 3 15 12 12
//  5 3 31 3 1 15 7
// Trick||Treat!
