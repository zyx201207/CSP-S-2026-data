#include <bits/stdc++.h>
using namespace std;

long long arr[500000+10];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,num = 0;
    bool dcsl = true;
    cin >> n >> m;
    cin >> arr[1];
    if (n == 1){
        cout << 1;
        return 0;
    }
    for (int i = 2 ; i <= n ; i++){
        cin >> arr[i];
        if (i > 2 && arr[i]-arr[i-1] != arr[i-1]-arr[i-2]){
            dcsl = false;
        }
    }
    sort(arr+1,arr+1+n);

    if (dcsl && n > 5000){
        int mid = n/2+1,midcnt = 0;
        for (int i = mid ; i <= n ; i++){
            if (arr[i] == arr[mid]){
                midcnt++;
            }
        }
        for (int i = mid-1 ; i >= 1 ; i--){
            if (arr[i] == arr[mid]){
                midcnt++;
            }
        }
        for (int i = mid ; i >= 1 && m > 0 ; i--){
            if (arr[mid] - arr[i] != 0 && m >= arr[mid] - arr[i]){
                m -= arr[mid]-arr[i];
                num++;
            }
        }
        cout << num+midcnt;
        return 0;
    }else if(n <= 5000 || 1){//...
        int maxq = 1;
        for (int i = 2 ; i <= n ; i++){
            int tm = m;
            int midcnt = 1;
            for (int j = i+1; j <= n ; j++){
                if (arr[j] == arr[i]){
                    midcnt++;
                }
            }
            for (int j = i-1; j >= 1 ; j--){
                if (arr[j] == arr[i]){
                    midcnt++;
                }
            }

            int num = 0;
            for (int j = i ; j >= 1&&tm > 0; j --){
                if (tm >= arr[i]-arr[j] && arr[i] != arr[j]){
                    tm -= arr[i]-arr[j];
                    num++;
                }
            }
            maxq = max(maxq,num+midcnt);
        }
        cout << maxq;
        return 0;
    }
    return 0;
}
