#include <bits/stdc++.h>
using namespace std;
int a[200005],n,L,R,len,r,tot,l;
char c[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        scanf("%c",&c[i]);
    }L = 1,R = n;
    while(L < R){
        if(a[L] == a[R]){
            if(c[L] == c[R]){
                ans += a[L];
            }L++,R--;
        }else{
            if(a[L] > a[R]){
                len = a[L],r = R,tot = a[R];
                while(len > tot){
                    r--;
                    tot += a[r];
                }for(int j = R;j >= r;j--){
                    if(len < a[j]){
                        a[j] -= len;
                        if(c[L] != c[j]){
                            ans += len;
                        }break;
                    }else{
                        len -= a[j];
                        if(c[L] != c[j]){
                            ans += a[j];
                        }R--;
                    }
                }L++;
            }else{
                len = a[R],l = L,tot = a[L];
                while(len > tot){
                    l++;
                    tot += a[l];
                }for(int j = L;j <= l;j++){
                    if(len < a[j]){
                        a[j] -= len;
                        if(c[R] != c[j]){
                            ans += len;
                        }break;
                    }else{
                        len -= a[j];
                        if(c[R] != c[j]){
                            ans += a[j];
                        }L++;
                    }
                }R--;
            }
        }
    }cout << ans << '\n';
    return 0;
}
