#include<bits/stdc++.h>
using namespace std;

int a[50005];
int main(){
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    sort (a,a+n);
    int maxn=0;
    for (int i=a[0]; i<=a[n-1]; i++){
        int cnt = 0,o = m;
        for (int j=n-1; a[j]<=i&&j>=0; j--){
            if (a[j]==i) cnt++;
            else if(o>=i-a[j]){
                o -= i-a[j];
                cnt++;
            }
        }
        if (cnt>=maxn) maxn = cnt;
    }
    cout << maxn;
    return 0;
}
