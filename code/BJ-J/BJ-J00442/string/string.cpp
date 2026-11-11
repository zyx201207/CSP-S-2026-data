#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long L, ans;
struct node{
    long long n;
    char c;
} a[N];
int n;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    int k = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[k].n >> a[k].c;
        L += a[k].n;
        if(a[k].c == a[k - 1].c){
            a[k - 1].n += a[k].n;
            continue;
        }
        k++;
    }
    k--;
    int left = 1, right = k;
    while(left < right){
        if(a[left].c == a[right].c){
            int temp = min(a[left].n, a[right].n);
            if(a[left].n < a[right].n){
                a[right].n -= a[left].n;
                left++;
            }
            else if(a[left].n > a[right].n){
                a[left].n -= a[right].n;
                right--;
            }
            else{
                left++;
                right--;
            }
        }
        else{
            int temp = min(a[left].n, a[right].n);
            ans += temp;
            if(a[left].n < a[right].n){
                a[right].n -= a[left].n;
                left++;
            }
            else if(a[left].n > a[right].n){
                a[left].n -= a[right].n;
                right--;
            }
            else{
                left++;
                right--;
            }
        }
    }
    cout << ans;
    return 0;
}
