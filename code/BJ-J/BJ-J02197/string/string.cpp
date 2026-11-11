#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin >> n;
    int a[n];
    char b[n];
    long long c = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        c += a[i];
    }
    int x = 0, y = 0;
    long long ans = 0;
    long long x1 = 0, y1 = 0;
    int j = 1;
    for(int i = 0; ; ){
        if(x1 + a[i] >= c / 2 || y1 + a[n-j] >= c / 2){
            if(b[i] != b[n-j]){
                ans += min(c / 2 - x1, c / 2 - y1);
            }
            break;
        }
        x1 += a[i];y1 += a[n-j];
        if(b[i] != b[n-j]){
            if(a[i] - x < a[n-j] - y){
                ans += a[i] - x;
                y = a[n-j] - y - (a[i] - x);
                x = 0;i++;
            }else{
                ans += b[i] - y;
                x = a[i] - x - (a[n-j] - y);
                y = 0;j++;
            }
        }else{
            if(a[i] - x < a[n-j] - y){
                x = 0;i++;
            }else{
                y = 0;j++;
            }
        }
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
