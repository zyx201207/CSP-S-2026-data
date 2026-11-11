#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, amt, o=1, maxn = 0;
    cin >> n >> amt;
    int a[n+10];
    for(int i=1;i<=n;i++)
        cin >> a[i];

    if(amt = 2){
        for(int i=o;i<=n-1;i++){
            for(int j=o+1;j<=n;j++){
                int num = 0;
                num = a[i]&a[j];
                if(num>maxn){
                    maxn = num;
                }
            }
            o+=1;
        }
    }
    cout << maxn;
    return 0;
}
