#include<bits/stdc++.h>
using namespace std;

long long a[100005];
char b[100005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
    }
    int l = 1,r = n;

    while(l < r){
        if(b[l] != b[r]){
            if(a[l] == a[r]){
                sum += a[r];
                l++;
                r--;
            }else if(a[l] < a[r]){
                sum += a[l];
                a[r] -= a[l];
                l++;
            }else{
                sum += a[r];
                a[l] -= a[r];
                r--;
            }
        }else{
            if(a[l] == a[r]){
                l++;
                r--;
            }else if(a[l] < a[r]){
                a[r] -= a[l];
                l++;
            }else{
                a[l] -= a[r];
                r--;
            }
        }
    }
    cout << sum;
    return 0;
}
