#include <bits/stdc++.h>
using namespace std;
long long a[101010101];
char b[101010101];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i]>>b[i];
    }
    long long ans = 0;
    long long l = 0,k = n - 1;
    while(l <= k){
        if(b[l] != b[k]){
            if(a[l] > a[k]){
                ans += a[k];
                a[l] -= a[k];
                k--;
            }else if(a[l] < a[k]){
                ans += a[l];
                a[k] -= a[l];
                l++;
            }else{
                ans += a[l];
                l++,k--;
            }
        }else{
            if(a[l] > a[k]){
                a[l] -= a[k];
                k--;
            }else if(a[l] < a[k]){
                a[k] -= a[l];
                l++;
            }else{
                l++,k--;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
