#include<bits/stdc++.h>
#define re register
using namespace std;
const int N = 2e5 + 100;
int n;
long long k[N];
char a[N];
long long ans ;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(re int i = 1;i <= n;i ++){
        cin >> k[i] >> a[i];
    }
    int l = 1,r = n;
    while(l < r){
        if(a[l] == a[r]){
            if(k[l] == k[r]){
                l ++,r--;
            }
            else if(k[l] < k[r]){
                k[r] -= k[l];
                l ++;
            }
            else {
                k[l] -= k[r];
                r --;
            }
        }else {
            if(k[l] == k[r]){
                ans += k[r];
                l ++,r--;
            }
            else if(k[l] < k[r]){
                ans += k[l];
                k[r] -= k[l];
                l ++;
            }
            else {
                ans += k[r];
                k[l] -= k[r];
                r --;
            }
        }
    }
    cout << ans;
	return 0;
}
