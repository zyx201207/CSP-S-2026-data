#include<iostream>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,a[N + 1];
char c[N + 1];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i]>>c[i];
    int l = 0,r = 0,i = 1,j = n,ans = 0;
    while(i < j){
        if(a[i] - l == a[j] - r){
            if(c[i] != c[j]) ans += a[i] - l;
            l = 0,r = 0,i++,j--;
        }
        else if(a[i] - l < a[j] - r){
            if(c[i] != c[j]) ans += a[i] - l;
            r += a[i] - l,i++,l = 0;
        }
        else{
            if(c[i] != c[j]) ans += a[j] - r;
            l += a[j] - r,j--,r = 0;
        }
    }
    cout<<ans<<"\n";
}
