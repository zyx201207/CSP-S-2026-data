#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N];
char c[N];
long long cnt = 0;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i] >> c[i];
    }
    for(int i = 1 , j = n;i <= j;  ){
        if(c[i] == c[j]){
            if(a[i] < a[j]){
                a[j] -= a[i];
                a[i] = 0;
                i ++;
            }else if(a[i] > a[j]){
                a[i] -= a[j];
                a[j] = 0;
                j --;
            }else{
                a[i] = a[j] = 0;
                i ++;
                j --;
            }
        }else{
            if(a[i] < a[j]){
                a[j] -= a[i];
                cnt += a[i];
                a[i] = 0;
                i ++;
            }else if(a[i] > a[j]){
                a[i] -= a[j];
                cnt += a[j];
                a[j] = 0;
                j --;
            }else{
                cnt += a[i];
                a[i] = a[j] = 0;
                i ++;
                j --;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
