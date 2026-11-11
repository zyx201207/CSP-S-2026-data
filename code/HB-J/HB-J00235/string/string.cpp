#include<iostream>
#include<string>
using namespace std;
const int N = 2e5 + 10;
string s[N];
char c[N];
int a[N],n;
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> a[i] >> c[i];
    int i = 1,j = n;
    while (i < j){
        while (a[i] > a[j]){
            a[i] -= a[j];
            if (c[i] != c[j])
                cnt += a[j];
            j--;
        }
        if (a[i] == a[j]){
            if (c[i] != c[j])
                cnt += a[i];
            i++;
            j--;
        }
        while (a[i] < a[j]){
            a[j] -= a[i];
            if (c[i] != c[j])
                cnt += a[i];
            i++;
        }
    }
    cout << cnt;
    return 0;
}
